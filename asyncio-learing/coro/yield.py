#!/bin/usr/env python3

import time

def func():
    yield time.sleep(2)
    print("after sleep")

a = func()
print(next(a))
print(next(a))
print("after call")
#print(next(a))

