#!/usr/bin/env python2.7

a = [1,3, 9, 10, 20, 30]
b = [2, 4, 5, 9, 21, 100, 122]

lena = len(a)
lenb = len(b)

i = j = 0
res = []

while(i < lena or j < lenb):
    if (i >= lena):
        res.append(b[j])
        j = j + 1
    elif (j >= lenb):
        res.append(a[i])
        i = i + 1
    elif (a[i] <= b[j]):
        res.append(a[i])
        i = i + 1
    else:
        res.append(b[j])
        j = j + 1

print res 
