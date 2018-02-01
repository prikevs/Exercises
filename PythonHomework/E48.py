#!/usr/bin/env python2.7

def printDiamond(f, n):
    for i in range(0, n):
        for j in range(0, n - i -1):
            f.write("  ")
        for j in range(0, i*2 + 1):
            f.write("* ")
        f.write("\n")
    for i in range(0, n - 1):
        for j in range(0, i+1):
            f.write("  ")
        for j in range(0, (n-i-1)*2-1):
            f.write("* ")
        f.write("\n")

def main():
    f = open("rhombus.txt", "w")
    n = int(raw_input("Input n: "))
    printDiamond(f, n)
    f.close()

if __name__ == '__main__':
    main()
