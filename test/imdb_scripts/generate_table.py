#!/bin/python

import string
import random
import sys
import json
from random import randint

def id_generator(size=10, chars=string.ascii_uppercase + string.digits + string.ascii_lowercase):
	return ''.join(random.choice(chars) for _ in range(size))


columns = 100
rows = 1000000
output = "testtable.tbl"
distinctValues = 100;

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
	if column % 2 == 0:
		column_types += "INTEGER"
	else:
		column_types += "STRING"

outFile.write(column_types + "\n")


# generate Header (storage type)
storage_types = ""
for column in range(0,columns):
	if column > 0:
		storage_types += "|"
	storage_types += str(column) + "_C" #make all column store

outFile.write(storage_types + "\n")
outFile.write("===\n")


randomStrings = []
randomIntegers = []

for i in range(0,distinctValues):
	randomStrings.append(id_generator());
	randomIntegers.append(randint(0,100000));

for row in range(0,rows):
	rowString = ""
	for column in range(0,columns):
		if column > 0:
			rowString += "|"
		if column % 2 == 0:
			rowString += str(randomIntegers[randint(0,len(randomIntegers)-1)])
		else:
			rowString += randomStrings[randint(0,len(randomStrings)-1)]
	outFile.write(rowString + "\n")


# create single column queries
for column in range(0,columns):

	with open('scan_test.json') as data_file:
		data = json.load(data_file)

	# simple table scan
	data["operators"]["scan"]["predicates"][0]["f"] = column

	if column % 2 == 0:
		data["operators"]["scan"]["predicates"][0]["value"] = randomIntegers[randint(0,len(randomIntegers)-1)]
		data["operators"]["scan"]["predicates"][0]["vtype"] = 0
	else:
		data["operators"]["scan"]["predicates"][0]["value"] = randomStrings[randint(0,len(randomStrings)-1)]
		data["operators"]["scan"]["predicates"][0]["vtype"] = 2

	with open("queries/single/" + str(column) + "_no_index.json", 'w') as outfile:
		json.dump(data, outfile)

	# index scan
	with open('index_scan_test.json') as data_file:
			data = json.load(data_file)

	if column % 2 == 0:
		data["operators"]["scan"]["predicates"][0] = [column, randomIntegers[randint(0,len(randomIntegers)-1)]]
	else:
		data["operators"]["scan"]["predicates"][0] = [column, randomStrings[randint(0,len(randomStrings)-1)]]

	data["operators"]["scan"]["mainindex"] = "testtable_single_" + str(column)

	with open("queries/single/" + str(column) + "_with_index.json", 'w') as outfile:
		json.dump(data, outfile)

# create multi column queries

for (column1,column2) in [(1,2),(3,4)]:

	#table scan
	with open('scan_test_multi.json') as data_file:
		data = json.load(data_file)


	data["operators"]["scan"]["predicates"][1]["f"] = column1
	print(data["operators"]["scan"]["predicates"][1]["f"])

	if column1 % 2 == 0:
		data["operators"]["scan"]["predicates"][1]["value"] = randomIntegers[randint(0,len(randomIntegers)-1)]
		data["operators"]["scan"]["predicates"][1]["vtype"] = 0
	else:
		data["operators"]["scan"]["predicates"][1]["value"] = randomStrings[randint(0,len(randomStrings)-1)]
		data["operators"]["scan"]["predicates"][1]["vtype"] = 2


	data["operators"]["scan"]["predicates"][2]["f"] = column2
	print(data["operators"]["scan"]["predicates"][2]["f"])

	if column2 % 2 == 0:
		data["operators"]["scan"]["predicates"][2]["value"] = randomIntegers[randint(0,len(randomIntegers)-1)]
		data["operators"]["scan"]["predicates"][2]["vtype"] = 0
	else:
		data["operators"]["scan"]["predicates"][2]["value"] = randomStrings[randint(0,len(randomStrings)-1)]
		data["operators"]["scan"]["predicates"][2]["vtype"] = 2


	with open("queries/multi/" + str(column1) + str(column2) + "_no_index.json", 'w') as outfile:
		json.dump(data, outfile)


	# index scan
	with open('index_scan_multi.json') as data_file:
			data = json.load(data_file)

	if column1 % 2 == 0:
		data["operators"]["scan"]["predicates"][0] = [column1, randomIntegers[randint(0,len(randomIntegers)-1)]]
	else:
		data["operators"]["scan"]["predicates"][0] = [column1, randomStrings[randint(0,len(randomStrings)-1)]]

	if column2 % 2 == 0:
		data["operators"]["scan"]["predicates"][1] = [column2, randomIntegers[randint(0,len(randomIntegers)-1)]]
	else:
		data["operators"]["scan"]["predicates"][1] = [column2, randomStrings[randint(0,len(randomStrings)-1)]]

	data["operators"]["scan"]["mainindex"] = "testtable_multi_" + str(column1) + str(column2)

	with open("queries/multi/" + str(column1) + str(column2) + "_with_index.json", 'w') as outfile:
		json.dump(data, outfile)


	#multi
	with open('multi_test.json') as data_file:
		data = json.load(data_file)

	if column1 % 2 == 0:
		data["operators"]["indexscan"]["predicates"][0] = [column1, randomIntegers[randint(0,len(randomIntegers)-1)]]
	else:
		data["operators"]["indexscan"]["predicates"][0] = [column1, randomStrings[randint(0,len(randomStrings)-1)]]
	data["operators"]["indexscan"]["mainindex"] = "testtable_single_" + str(column1)

	data["operators"]["tablescan"]["predicates"][0]["f"] = column2
	print(data["operators"]["tablescan"]["predicates"][0]["f"])

	if column2 % 2 == 0:
		data["operators"]["tablescan"]["predicates"][0]["value"] = randomIntegers[randint(0,len(randomIntegers)-1)]
		data["operators"]["tablescan"]["predicates"][0]["vtype"] = 0
	else:
		data["operators"]["tablescan"]["predicates"][0]["value"] = randomStrings[randint(0,len(randomStrings)-1)]
		data["operators"]["tablescan"]["predicates"][0]["vtype"] = 2

	with open("queries/multi/" + str(column1) + str(column2) + "_with_single_index.json", 'w') as outfile:
		json.dump(data, outfile)