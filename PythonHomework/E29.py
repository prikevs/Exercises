#!/usr/bin/env python2.7

def insert(trie, word):
    p = trie
    for i in word:
        if i not in p:
            p[i] = [{}, 0] 
        p[i][1] = p[i][1] + 1
        p = p[i][0]

def query(trie, n):
    p = trie
    pre = []
    flag = True
    while flag:
        flag = False
        for index in p.keys():
            value = p[index]
            if value[1] == n:
                pre.append(index) 
                p = value[0]
                flag = True
                break
    return pre

def getMaxPrefix(strs):
    trie = {}
    for s in strs:
        insert(trie, s) 
    pre = query(trie, len(strs))
    return "".join(pre)

def main():
    n = int(raw_input("The number of the strings: "))
    strs = []
    for i in range(0, n):
        strs.append(raw_input("The %d string: " % (i+1))) 
    print(getMaxPrefix(strs))

if __name__ == '__main__':
    main()

