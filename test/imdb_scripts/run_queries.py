#!/bin/python


import requests
import json
from random import randint


numberOfQueries = 1000


outFile = open("results/single/phase_1.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = 0
	elif randomNumber < 70:
		column = 1
	elif randomNumber < 85:
		column = 2
	elif randomNumber < 95:
		column = 3
	else:
		column = 4


	data_file = open("queries/single/" + str(column) + "_no_index.json")

	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "\n")
	data_file.close()

outFile.close()


outFile = open("results/single/phase_2.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = 0
	elif randomNumber < 70:
		column = 1
	elif randomNumber < 85:
		column = 2
	elif randomNumber < 95:
		column = 3
	else:
		column = 4


	if column <=1:
		data_file = open("queries/single/" + str(column) + "_with_index.json")
	else:
		data_file = open("queries/single/" + str(column) + "_no_index.json")

	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "\n")
	data_file.close()

outFile.close()


outFile = open("results/single/phase_3.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = 3
	elif randomNumber < 70:
		column = 4
	elif randomNumber < 85:
		column = 2
	elif randomNumber < 95:
		column = 0
	else:
		column = 1


	if column <=1:
		data_file = open("queries/single/" + str(column) + "_with_index.json")
	else:
		data_file = open("queries/single/" + str(column) + "_no_index.json")

	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "\n")
	data_file.close()

outFile.close()


outFile = open("results/single/phase_4.csv", "w")
for i in range(0,numberOfQueries):

	randomNumber = randint(0,100)

	if randomNumber < 40:
		column = 3
	elif randomNumber < 70:
		column = 4
	elif randomNumber < 85:
		column = 0
	elif randomNumber < 95:
		column = 1
	else:
		column = 2


	if column >= 3:
		data_file = open("queries/single/" + str(column) + "_with_index.json")
	else:
		data_file = open("queries/single/" + str(column) + "_no_index.json")

	payload = {'performance': 'true', 'query': data_file}
	r = requests.post("http://localhost:5000/jsonQuery", data=payload)

	response = r.json()["performanceData"]

	totalTime = 0
	for planop in response:
		totalTime += planop["endTime"]-planop["startTime"]

	outFile.write(str(totalTime) + "\n")
	data_file.close()

outFile.close()