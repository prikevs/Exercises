#!/usr/bin/env python2.7

filename_in = raw_input("Name of input file:")
filename_out = raw_input("Name of output file:")

f_in = open(filename_in, "r")
f_out = open(filename_out, "w")

data = list(f_in.read())
data.reverse()
out = "".join(data)

f_out.write(out)

f_in.close()
f_out.close()
