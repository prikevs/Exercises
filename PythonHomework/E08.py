#!/usr/bin/env python2.7

filename = raw_input("Please input the filename:")
f = open(filename, "r+")
data = f.read()
a = raw_input("Please input the word you want to replace:")
b = raw_input("Please input what content you want to change to:")
data = data.replace(a, b)
f.write(data)
f.close()
print("Finished")
