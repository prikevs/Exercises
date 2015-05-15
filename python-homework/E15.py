#!/usr/bin/env python2.7

def trieInsert(trie, word):
    p = trie
    length = 0
    for a in word:
        length = length + 1
        if a not in p['next']:
            p['next'][a] = {"isword": 0, "number": 0, "next": {}}
        p['next'][a]["number"] = p['next'][a]["number"] + 1
        p = p['next'][a]
    p['isword'] = p['isword'] + 1

def trieQuery(trie):
    number = {}
    for index in trie['next']:
        number[index] = trie['next'][index]['number']
    for i in range(0, 26):
        ch = chr(ord('a') + i)
        if ch not in number:
            number[ch] = 0
    return number

def getWords(data):
    data = data.lower()
    words = data.split(' ')
    return words

def main():
    filename = raw_input("name of the file stored bible: ")
    f = open(filename, "r")
    data = f.read()
    words = getWords(data)
    trie = {'isword': 0, 'length': 0, 'next': {}}
    for word in words:
        trieInsert(trie, word)
    number = trieQuery(trie)
    print("%d words, as prefix a-z is:" % len(words))
    for i in range(0, 26):
        ch = chr(ord('a') + i)
        print("%c : %d" % (ch, number[ch]))

if __name__ == '__main__':
    main()
