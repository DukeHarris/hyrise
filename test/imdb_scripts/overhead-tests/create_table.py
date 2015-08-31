#!/bin/python

import string
import random
import sys
import json
from random import randint

def id_generator(size=10, chars=string.ascii_uppercase + string.digits + string.ascii_lowercase):
	return ''.join(random.choice(chars) for _ in range(size))


columns = 100
rows = 100000
output = "testtable.tbl"
distinctValues = 1000;

outFile = open(output,"w")

# generate Header (column names)
column_names = ""
for column in range(0,columns):
	if column > 0:
		column_names += "|"
	column_names += "col_" + str(column)

outFile.write(column_names + "\n")

# generate Header (data type)
column_types = ""
for column in range(0,columns):
	if column > 0:
		column_types += "|"
	column_types += "INTEGER"


outFile.write(column_types + "\n")


# generate Header (storage type)
storage_types = ""
for column in range(0,columns):
	if column > 0:
		storage_types += "|"
	storage_types += str(column) + "_C" #make all column store

outFile.write(storage_types + "\n")
outFile.write("===\n")


randomIntegers = []

for i in range(0,distinctValues):
	randomIntegers.append(randint(0,1000000));

for row in range(0,rows):
	rowString = ""
	for column in range(0,columns):
		if column > 0:
			rowString += "|"
		rowString += str(randomIntegers[randint(0,len(randomIntegers)-1)])
	outFile.write(rowString + "\n")

outFile.close()

#generate query files

for scannedColumns in [1, 5, 10, 25, 50, 100]:

	with open('scan_test_multi.json') as data_file:
		data = json.load(data_file)

	for i in range(0, scannedColumns-1):
		data["operators"]["scan"]["predicates"].append({"type": "OR"})

	for i in range(0, scannedColumns):
		data["operators"]["scan"]["predicates"].append({"type" : "EQ", "in" : 0, "f" : i, "value" : randomIntegers[randint(0,len(randomIntegers)-1)], "vtype": 0})

	with open("queries/" + str(scannedColumns) + "_columns.json", 'w') as outfile:
		json.dump(data, outfile)