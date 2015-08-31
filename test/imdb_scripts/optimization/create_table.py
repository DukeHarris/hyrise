#!/bin/python

import string
import random
import sys
import json
from random import randint
import os

def id_generator(size=10, chars=string.ascii_uppercase + string.digits + string.ascii_lowercase):
	return ''.join(random.choice(chars) for _ in range(size))


columns = 100
rows = 100000
output = "testtable.tbl"
distinctValues = [100,10000,5000,1000,100000] #repeating every 5 columns

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

for c in range(0,5):
	randomIntegers.append([])
	for i in range(0,distinctValues[c]):
		randomIntegers[c].append(randint(0,1000000));

for row in range(0,rows):
	rowString = ""
	for column in range(0,columns):
		if column > 0:
			rowString += "|"
		rowString += str(randomIntegers[column % 5][randint(0,len(randomIntegers[column % 5])-1)])
	outFile.write(rowString + "\n")

outFile.close()

os.system("tail -n20 " + output + " > sample.csv")