#!/bin/python

import math
from random import randint
import csv
import json
import requests
import os
import operator

#inputs: distinct values per column (width of AVs), memory budget

distinctValues = [100,10000,5000,1000,100000] #repeating every 5 columns
tableSize = 100000
numberOfQueries = 1000
memoryBudget = 20000000 #in byte

scanStats = {}
createdIndices = []
usableIndices = []

workload = []

os.system("mkdir -p results")


def getAVSize(column):
	distinct = distinctValues[column % 5]
	return math.ceil(math.log2(distinct))

def getIndexSize(columns):
	widthOfP = 0
	for column in columns:
		widthOfP += getAVSize(column)

	power = 3
	while math.pow(2,power) < widthOfP:
		power += 1

	bitsUsed = math.pow(2,power)

	size = (tableSize * bitsUsed/8) + (math.ceil(math.log2(tableSize)) * tableSize) / 8

	return size


def createIndex(columns):

	with open('create-index-template.json') as data_file:
		data = json.load(data_file)

	data["operators"]["create"]["fields"] = ["col_"+str(x) for x in columns]
	data["operators"]["create"]["index_name"] = "testtable_idx_" + '_'.join(str(x) for x in columns)

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	createdIndices.append('_'.join(str(x) for x in columns))



with open('sample.csv', 'r') as f:
    reader = csv.reader(f, delimiter="|")
    sample = list(reader)


###################
# Phase 1
#################

for q in range(0, numberOfQueries):

	randomNumber = randint(1,100)
	if randomNumber < 50:
		numberColumnsScanned = 3
	elif randomNumber < 75:
		numberColumnsScanned = 4
	elif randomNumber < 90:
		numberColumnsScanned = 1
	else:
		numberColumnsScanned = 2

	columnsScanned = []

	n = 0
	while n < numberColumnsScanned:
		column = randint(0,5)
		if not column in columnsScanned:
			columnsScanned.append(column)
			n += 1

	columnsScanned.sort()

	sampleRow = sample[randint(0,19)]

	#run queries without index
	with open('scan-template.json') as data_file:
		data = json.load(data_file)

	for i in range(0, len(columnsScanned)-1):
		data["operators"]["scan"]["predicates"].append({"type": "AND"})

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-1-no-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()


	columnKey = '_'.join(str(x) for x in columnsScanned)
	if columnKey in scanStats:
		scanStats[columnKey] += 1
	else:
		scanStats[columnKey] = 1


	#run queries without indices again (to get data before optimization)

	with open('scan-template.json') as data_file:
		data = json.load(data_file)

	for i in range(0, len(columnsScanned)-1):
		data["operators"]["scan"]["predicates"].append({"type": "AND"})

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-1-optimized-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()


	#run queries with indices for everything
	if not columnKey in createdIndices:
		createIndex(columnsScanned)

	with open('index-template.json') as data_file:
		data = json.load(data_file)

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

	data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-1-all-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()

	workload.append(columnsScanned)

sortedStats = sorted(scanStats.items(), key=operator.itemgetter(1), reverse=True)
print(sortedStats)


#####################
# optimization
######################

usableIndices = []

totalIndexSize = 0
for columnsKey in sortedStats:
	columns = [int(x) for x in columnsKey[0].split("_")]

	if (totalIndexSize + getIndexSize(columns)) < memoryBudget:
		usableIndices.append(columns)
		totalIndexSize += getIndexSize(columns)
	else:
		for i in range(1,len(columns)):
			if (totalIndexSize + getIndexSize(columns[:-i])) < memoryBudget:
				usableIndices.append(columns[:-i])
				totalIndexSize += getIndexSize(columns[:-i])
				break

print(totalIndexSize, usableIndices)

scanStats = {}

###################
# Phase 2
#################

for columnsScanned in workload:

	# randomNumber = randint(1,100)
	# if randomNumber < 50:
	# 	numberColumnsScanned = 3
	# elif randomNumber < 75:
	# 	numberColumnsScanned = 4
	# elif randomNumber < 90:
	# 	numberColumnsScanned = 1
	# else:
	# 	numberColumnsScanned = 2

	# columnsScanned = []

	# n = 0
	# while n < numberColumnsScanned:
	# 	column = randint(0,5)
	# 	if not column in columnsScanned:
	# 		columnsScanned.append(column)
	# 		n += 1

	# columnsScanned.sort()

	sampleRow = sample[randint(0,19)]

	#run queries without index
	with open('scan-template.json') as data_file:
		data = json.load(data_file)

	for i in range(0, len(columnsScanned)-1):
		data["operators"]["scan"]["predicates"].append({"type": "AND"})

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-2-no-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()


	columnKey = '_'.join(str(x) for x in columnsScanned)
	if columnKey in scanStats:
		scanStats[columnKey] += 1
	else:
		scanStats[columnKey] = 1


	#repeat all indices
	if not columnKey in createdIndices:
		createIndex(columnsScanned)

	with open('index-template.json') as data_file:
		data = json.load(data_file)

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

	data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-2-all-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()



	#repeat optimized but use usableIndices
	scanned = False
	if columnsScanned in usableIndices: #use index

		print("index used", columnsScanned)

		with open('index-template.json') as data_file:
			data = json.load(data_file)

		for i in columnsScanned:
			data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

		data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


		payload = {'performance': 'true', 'query': json.dumps(data)}
		r = requests.post("http://localhost:5000/jsonQuery", data=payload)

		response = r.json()["performanceData"]

		totalTime = 0
		for planop in response:
			totalTime += planop["endTime"]-planop["startTime"]

		outFile = open("results/phase-2-optimized-index.csv", "a")
		outFile.write(str(totalTime) + "\n")
		outFile.close()



	else:
		for i in range(1,len(columnsScanned)):
			if columnsScanned[:-i] in usableIndices:

				print("partial index used", columnsScanned, columnsScanned[:-i])

				with open('multi-template.json') as data_file:
					data = json.load(data_file)

				#use index for columnsScanned[:-i]
				for j in columnsScanned[:-i]:
					data["operators"]["indexscan"]["predicates"].append([j, int(sampleRow[j])])
				data["operators"]["indexscan"]["mainindex"] = "testtable_idx_" + '_'.join(str(x) for x in columnsScanned[:-i])

				#use table scan for columnsScanned[-i:]
				for j in range(0, len(columnsScanned[-i:])-1):
					data["operators"]["tablescan"]["predicates"].append({"type": "AND"})

				for j in columnsScanned[-i:]:
					data["operators"]["tablescan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : j, "value" : int(sampleRow[j]), "vtype": 0})


				payload = {'performance': 'true', 'query': json.dumps(data)}
				r = requests.post("http://localhost:5000/jsonQuery", data=payload)

				response = r.json()["performanceData"]

				totalTime = 0
				for planop in response:
					totalTime += planop["endTime"]-planop["startTime"]

				outFile = open("results/phase-2-optimized-index.csv", "a")
				outFile.write(str(totalTime) + "\n")
				outFile.close()


				scanned=True
				break

		if not scanned:
			with open('scan-template.json') as data_file:
				data = json.load(data_file)

			for i in range(0, len(columnsScanned)-1):
				data["operators"]["scan"]["predicates"].append({"type": "AND"})

			for i in columnsScanned:
				data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

			payload = {'performance': 'true', 'query': json.dumps(data)}
			r = requests.post("http://localhost:5000/jsonQuery", data=payload)

			response = r.json()["performanceData"]

			totalTime = 0
			for planop in response:
				totalTime += planop["endTime"]-planop["startTime"]

			outFile = open("results/phase-2-optimized-index.csv", "a")
			outFile.write(str(totalTime) + "\n")
			outFile.close()

###################
# Phase 3 (Workload Change)
#################

workload = [ [y + 5 for y in x] for x in workload]

for columnsScanned in workload:

	# randomNumber = randint(1,100)
	# if randomNumber < 50:
	# 	numberColumnsScanned = 3
	# elif randomNumber < 75:
	# 	numberColumnsScanned = 4
	# elif randomNumber < 90:
	# 	numberColumnsScanned = 1
	# elif randomNumber < 95:
	# 	numberColumnsScanned = 2
	# else:
	# 	numberColumnsScanned = 5

	# columnsScanned = []

	# n = 0
	# while n < numberColumnsScanned:
	# 	column = randint(3,8)
	# 	if not column in columnsScanned:
	# 		columnsScanned.append(column)
	# 		n += 1

	# columnsScanned.sort()

	sampleRow = sample[randint(0,19)]

	#run queries without index
	with open('scan-template.json') as data_file:
		data = json.load(data_file)

	for i in range(0, len(columnsScanned)-1):
		data["operators"]["scan"]["predicates"].append({"type": "AND"})

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-3-no-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()


	columnKey = '_'.join(str(x) for x in columnsScanned)
	if columnKey in scanStats:
		scanStats[columnKey] += 1
	else:
		scanStats[columnKey] = 1


	#repeat all indices
	if not columnKey in createdIndices:
		createIndex(columnsScanned)

	with open('index-template.json') as data_file:
		data = json.load(data_file)

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

	data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-3-all-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()



	#repeat optimized but use usableIndices
	scanned = False
	if columnsScanned in usableIndices: #use index

		print("index used", columnsScanned)

		with open('index-template.json') as data_file:
			data = json.load(data_file)

		for i in columnsScanned:
			data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

		data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


		payload = {'performance': 'true', 'query': json.dumps(data)}
		r = requests.post("http://localhost:5000/jsonQuery", data=payload)

		response = r.json()["performanceData"]

		totalTime = 0
		for planop in response:
			totalTime += planop["endTime"]-planop["startTime"]

		outFile = open("results/phase-3-optimized-index.csv", "a")
		outFile.write(str(totalTime) + "\n")
		outFile.close()



	else:
		for i in range(1,len(columnsScanned)):
			if columnsScanned[:-i] in usableIndices:

				print("partial index used", columnsScanned, columnsScanned[:-i])

				with open('multi-template.json') as data_file:
					data = json.load(data_file)

				#use index for columnsScanned[:-i]
				for j in columnsScanned[:-i]:
					data["operators"]["indexscan"]["predicates"].append([j, int(sampleRow[j])])
				data["operators"]["indexscan"]["mainindex"] = "testtable_idx_" + '_'.join(str(x) for x in columnsScanned[:-i])

				#use table scan for columnsScanned[-i:]
				for j in range(0, len(columnsScanned[-i:])-1):
					data["operators"]["tablescan"]["predicates"].append({"type": "AND"})

				for j in columnsScanned[-i:]:
					data["operators"]["tablescan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : j, "value" : int(sampleRow[j]), "vtype": 0})


				payload = {'performance': 'true', 'query': json.dumps(data)}
				r = requests.post("http://localhost:5000/jsonQuery", data=payload)

				response = r.json()["performanceData"]

				totalTime = 0
				for planop in response:
					totalTime += planop["endTime"]-planop["startTime"]

				outFile = open("results/phase-3-optimized-index.csv", "a")
				outFile.write(str(totalTime) + "\n")
				outFile.close()


				scanned=True
				break

		if not scanned:
			with open('scan-template.json') as data_file:
				data = json.load(data_file)

			for i in range(0, len(columnsScanned)-1):
				data["operators"]["scan"]["predicates"].append({"type": "AND"})

			for i in columnsScanned:
				data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

			payload = {'performance': 'true', 'query': json.dumps(data)}
			r = requests.post("http://localhost:5000/jsonQuery", data=payload)

			response = r.json()["performanceData"]

			totalTime = 0
			for planop in response:
				totalTime += planop["endTime"]-planop["startTime"]

			outFile = open("results/phase-3-optimized-index.csv", "a")
			outFile.write(str(totalTime) + "\n")
			outFile.close()


#####################
# optimization
######################

usableIndices = []

totalIndexSize = 0
for columnsKey in sortedStats:
	columns = [int(x) for x in columnsKey[0].split("_")]

	if (totalIndexSize + getIndexSize(columns)) < memoryBudget:
		usableIndices.append(columns)
		totalIndexSize += getIndexSize(columns)
	else:
		for i in range(1,len(columns)):
			if (totalIndexSize + getIndexSize(columns[:-i])) < memoryBudget:
				usableIndices.append(columns[:-i])
				totalIndexSize += getIndexSize(columns[:-i])
				break

print(totalIndexSize, usableIndices)

scanStats = {}


###################
# Phase 4 (New Workload after Optimization)
#################


for columnsScanned in workload:

	# randomNumber = randint(1,100)
	# if randomNumber < 50:
	# 	numberColumnsScanned = 3
	# elif randomNumber < 75:
	# 	numberColumnsScanned = 4
	# elif randomNumber < 90:
	# 	numberColumnsScanned = 1
	# else:
	# 	numberColumnsScanned = 2

	# columnsScanned = []

	# n = 0
	# while n < numberColumnsScanned:
	# 	column = randint(4,9)
	# 	if not column in columnsScanned:
	# 		columnsScanned.append(column)
	# 		n += 1

	# columnsScanned.sort()

	sampleRow = sample[randint(0,19)]

	#run queries without index
	with open('scan-template.json') as data_file:
		data = json.load(data_file)

	for i in range(0, len(columnsScanned)-1):
		data["operators"]["scan"]["predicates"].append({"type": "AND"})

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-4-no-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()


	columnKey = '_'.join(str(x) for x in columnsScanned)
	if columnKey in scanStats:
		scanStats[columnKey] += 1
	else:
		scanStats[columnKey] = 1


	#repeat all indices
	if not columnKey in createdIndices:
		createIndex(columnsScanned)

	with open('index-template.json') as data_file:
		data = json.load(data_file)

	for i in columnsScanned:
		data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

	data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


	payload = {'performance': 'true', 'query': json.dumps(data)}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	if not "performanceData" in r.json():
		print(r.json(), columnsScanned)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile = open("results/phase-4-all-index.csv", "a")
	outFile.write(str(totalTime) + "\n")
	outFile.close()



	#repeat optimized but use usableIndices
	scanned = False
	if columnsScanned in usableIndices: #use index

		print("index used", columnsScanned)

		with open('index-template.json') as data_file:
			data = json.load(data_file)

		for i in columnsScanned:
			data["operators"]["scan"]["predicates"].append([i, int(sampleRow[i])])

		data["operators"]["scan"]["mainindex"] = "testtable_idx_" + columnKey


		payload = {'performance': 'true', 'query': json.dumps(data)}
		r = requests.post("http://localhost:5000/jsonQuery", data=payload)

		response = r.json()["performanceData"]

		totalTime = 0
		for planop in response:
			totalTime += planop["endTime"]-planop["startTime"]

		outFile = open("results/phase-4-optimized-index.csv", "a")
		outFile.write(str(totalTime) + "\n")
		outFile.close()



	else:
		for i in range(1,len(columnsScanned)):
			if columnsScanned[:-i] in usableIndices:

				print("partial index used", columnsScanned, columnsScanned[:-i])

				with open('multi-template.json') as data_file:
					data = json.load(data_file)

				#use index for columnsScanned[:-i]
				for j in columnsScanned[:-i]:
					data["operators"]["indexscan"]["predicates"].append([j, int(sampleRow[j])])
				data["operators"]["indexscan"]["mainindex"] = "testtable_idx_" + '_'.join(str(x) for x in columnsScanned[:-i])

				#use table scan for columnsScanned[-i:]
				for j in range(0, len(columnsScanned[-i:])-1):
					data["operators"]["tablescan"]["predicates"].append({"type": "AND"})

				for j in columnsScanned[-i:]:
					data["operators"]["tablescan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : j, "value" : int(sampleRow[j]), "vtype": 0})


				payload = {'performance': 'true', 'query': json.dumps(data)}
				r = requests.post("http://localhost:5000/jsonQuery", data=payload)

				response = r.json()["performanceData"]

				totalTime = 0
				for planop in response:
					totalTime += planop["endTime"]-planop["startTime"]

				outFile = open("results/phase-4-optimized-index.csv", "a")
				outFile.write(str(totalTime) + "\n")
				outFile.close()


				scanned=True
				break

		if not scanned:
			with open('scan-template.json') as data_file:
				data = json.load(data_file)

			for i in range(0, len(columnsScanned)-1):
				data["operators"]["scan"]["predicates"].append({"type": "AND"})

			for i in columnsScanned:
				data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : int(sampleRow[i]), "vtype": 0})

			payload = {'performance': 'true', 'query': json.dumps(data)}
			r = requests.post("http://localhost:5000/jsonQuery", data=payload)

			response = r.json()["performanceData"]

			totalTime = 0
			for planop in response:
				totalTime += planop["endTime"]-planop["startTime"]

			outFile = open("results/phase-4-optimized-index.csv", "a")
			outFile.write(str(totalTime) + "\n")
			outFile.close()