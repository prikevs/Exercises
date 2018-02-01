#!/usr/bin/env python2.7

def getAverage(ele):
    s = 0
    for i in ele:
        s = s + i
    return s * 1.0 / len(ele)

def getMax(ele):
    m = -1
    for i in ele:
        if i > m:
            m = i
    return m 

def cacMod(ele):
    res = 0
    for i in ele:
        if i % 3 == 0 or i % 5 == 0:
            res = res + 1
    return res

def handleData(data):
    l1 = data.split("\n")
    ele = []
    e = []
    for i in l1:
        l2 = i.split(',')
        e = e + l2
    for i in range(0, len(e)):
        try:
            ne = int(e[i])
        except Exception:
            continue
        ele.append(ne)
    return ele

def main():
    filename = raw_input("Input the filename: ")
    f = open(filename)
    data = f.read()
    ele = handleData(data)
    print "Average is: ", getAverage(ele)
    print "Max is: ", getMax(ele)
    print "Mod is: ", cacMod(ele)

if __name__ == '__main__':
    main()
