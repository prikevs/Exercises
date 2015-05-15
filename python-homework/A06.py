#!/usr/bin/env python2.7

def sumN(n):
    s = 0
    for i in range(0, n):
        s = s + i
    return s

def sumNCubes(n):
    s = 0
    for i in range(0, n):
        s = s + i ** 3
    return s

def main():
    n = int(raw_input("Input n:"))
    print("sumN:", sumN(n))
    print("sumNCubes:", sumNCubes(n))

if __name__ == '__main__':
    main()
