#!/usr/bin/env python2.7

def getTriangle(n):
    tr = [[0 for j in range(0, n)] for i in range(0, n)] 
    for i in range(0, n):
        tr[i][i] = 1
        tr[i][0] = 1
    for i in range(1, n):
        for j in range(1, i):
            tr[i][j] = tr[i-1][j-1] + tr[i-1][j]
    return tr

def printTriangle(tr):
    n = len(tr) 
    for i in range(0, n):
        for j in range(n-1, i, -1):
            print " ",
        for k in range(0, i + 1):
            print tr[i][k], " ",
        print("")
    
def main():
    n = int(raw_input("Please input n: "))
    tr = getTriangle(n) 
    printTriangle(tr)

if __name__ == '__main__':
    main()
