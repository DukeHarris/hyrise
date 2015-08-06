#!/bin/python


import requests
import json
from random import randint


numberOfQueries = 1000


# outFile = open("results/single/phase_1.csv", "w")
# for i in range(0,numberOfQueries):

# 	randomNumber = randint(0,100)

# 	if randomNumber < 40:
# 		column = 0
# 	elif randomNumber < 70:
# 		column = 1
# 	elif randomNumber < 85:
# 		column = 2
# 	elif randomNumber < 95:
# 		column = 3
# 	else:
# 		column = 4


# 	data_file = open("queries/single/" + str(column) + "_no_index.json")

# 	payload = {'performance': 'true', 'query': data_file}
# 	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

# 	response = r.json()["performanceData"]

# 	totalTime = 0
# 	for planop in response:
# 		totalTime += planop["endTime"]-planop["startTime"]

# 	outFile.write(str(totalTime) + "," + str(column) + "\n")
# 	data_file.close()

# outFile.close()


# outFile = open("results/single/phase_2.csv", "w")
# for i in range(0,numberOfQueries):

# 	randomNumber = randint(0,100)

# 	if randomNumber < 40:
# 		column = 0
# 	elif randomNumber < 70:
# 		column = 1
# 	elif randomNumber < 85:
# 		column = 2
# 	elif randomNumber < 95:
# 		column = 3
# 	else:
# 		column = 4


# 	if column <=1:
# 		data_file = open("queries/single/" + str(column) + "_with_index.json")
# 	else:
# 		data_file = open("queries/single/" + str(column) + "_no_index.json")

# 	payload = {'performance': 'true', 'query': data_file}
# 	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

# 	response = r.json()["performanceData"]

# 	totalTime = 0
# 	for planop in response:
# 		totalTime += planop["endTime"]-planop["startTime"]

# 	outFile.write(str(totalTime) + "," + str(column) + "\n")
# 	data_file.close()

# outFile.close()


# outFile = open("results/single/phase_3.csv", "w")
# for i in range(0,numberOfQueries):

# 	randomNumber = randint(0,100)

# 	if randomNumber < 40:
# 		column = 3
# 	elif randomNumber < 70:
# 		column = 4
# 	elif randomNumber < 85:
# 		column = 2
# 	elif randomNumber < 95:
# 		column = 0
# 	else:
# 		column = 1


# 	if column <=1:
# 		data_file = open("queries/single/" + str(column) + "_with_index.json")
# 	else:
# 		data_file = open("queries/single/" + str(column) + "_no_index.json")

# 	payload = {'performance': 'true', 'query': data_file}
# 	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

# 	response = r.json()["performanceData"]

# 	totalTime = 0
# 	for planop in response:
# 		totalTime += planop["endTime"]-planop["startTime"]

# 	outFile.write(str(totalTime) + "," + str(column) + "\n")
# 	data_file.close()

# outFile.close()


# outFile = open("results/single/phase_4.csv", "w")
# for i in range(0,numberOfQueries):

# 	randomNumber = randint(0,100)

# 	if randomNumber < 40:
# 		column = 3
# 	elif randomNumber < 70:
# 		column = 4
# 	elif randomNumber < 85:
# 		column = 0
# 	elif randomNumber < 95:
# 		column = 1
# 	else:
# 		column = 2


# 	if column >= 3:
# 		data_file = open("queries/single/" + str(column) + "_with_index.json")
# 	else:
# 		data_file = open("queries/single/" + str(column) + "_no_index.json")

# 	payload = {'performance': 'true', 'query': data_file}
# 	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

# 	response = r.json()["performanceData"]

# 	totalTime = 0
# 	for planop in response:
# 		totalTime += planop["endTime"]-planop["startTime"]

# 	outFile.write(str(totalTime) + "," + str(column) + "\n")
# 	data_file.close()

# outFile.close()




outFile = open("results/multi/phase_1.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = "0"
	elif randomNumber < 70:
		column = "12"
	elif randomNumber < 90:
		column = "34"
	else:
		column = "1"


	if len(column) == 1:
		data_file = open("queries/single/" + column + "_no_index.json")
	else:
		data_file = open("queries/multi/" + column + "_no_index.json")

	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "," + str(column) + "\n")
	data_file.close()

outFile.close()

outFile = open("results/multi/phase_2.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = "0"
	elif randomNumber < 70:
		column = "12"
	elif randomNumber < 90:
		column = "34"
	else:
		column = "1"


	if column == "0":
		data_file = open("queries/single/" + column + "_with_index.json")
	elif len(column) == 2:
		data_file = open("queries/multi/" + column + "_with_index.json")
	else:
		data_file = open("queries/single/" + column + "_no_index.json")


	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "," + str(column) + "\n")
	data_file.close()

outFile.close()

outFile = open("results/multi/phase_3.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = "0"
	elif randomNumber < 70:
		column = "12"
	elif randomNumber < 90:
		column = "34"
	else:
		column = "1"


	if column == "0":
		data_file = open("queries/single/" + column + "_with_index.json")
	elif column == "12":
		data_file = open("queries/multi/" + column + "_with_index.json")
	elif column == "34":
		data_file = open("queries/multi/" + column + "_with_single_index.json")
	else:
		data_file = open("queries/single/" + column + "_no_index.json")


	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "," + str(column) + "\n")
	data_file.close()

outFile.close()