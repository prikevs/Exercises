#!/usr/bin/env python2.7

worda = raw_input("word A: ")
wordb = raw_input("word B: ")

ans = True

a = b = []

if len(worda) != len(wordb):
    ans = False
else:
    length = len(worda)
    for i in range(0, length):
        if worda[i] != wordb[i]:
            a.append(worda[i])
            b.append(wordb[i])
    l = len(a)
    i, j = 0, l - 1
    while i < j:
        if a[i] != b[i]:
            ans = False
            break
        i = i + 1
        j = j - 1

if ans:
    print "true"
else:
    print "false"

