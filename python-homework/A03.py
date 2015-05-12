#!/usr/bin/env python2.7

s = raw_input("Please input a string:")
ans = 0
for i in s:
    if i.islower():
        ans = ans + ord(i) - ord('a')  + 1
    elif i.isupper():
        ans = ans + ord(i) - ord('A')  + 1

print("The sum is %d" % (ans))
