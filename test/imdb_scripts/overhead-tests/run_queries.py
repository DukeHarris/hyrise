#!/bin/python


import requests
import json
from random import randint
import shutil
import os


numberOfQueries = 100
scannedColumns = [1,5,10,25,50,100]

os.system("mkdir -p results")

for n in range(0,numberOfQueries):
	for c in scannedColumns:

		outFile = open("results/"+ str(c) +"_columns.csv", "a")

		data_file = open("queries/" + str(c) + "_columns.json")

		payload = {'performance': 'true', 'query': data_file}
		r = requests.post("http://localhost:5000/jsonQuery", data=payload)

		response = r.json()["performanceData"]

		totalTime = 0
		for planop in response:
			totalTime += planop["endTime"]-planop["startTime"]

		outFile.write(str(totalTime) + "\n")
		data_file.close()

		outFile.close()