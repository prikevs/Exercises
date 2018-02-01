#!/usr/bin/env python2.7

def main():
    n = int(raw_input("Number of words: "))
    words = ''
    for i in range(0, n):
        word = raw_input("the %d word: " % (i + 1))
        words = words + word.lower()
    length = len(words)
    numbers = {}
    for ch in words:
        if ch in numbers:
            numbers[ch] = numbers[ch] + 1
        else:
            numbers[ch] = 1 
    print("length is %d" % (length))
    for i in range(0, 26):
        ch = chr(ord('a') + i)
        if ch not in numbers:
            numbers[ch] = 0
        print("%c : %.2f%%" % (ch, numbers[ch]*100.0 / length))

if __name__ == '__main__':
    main()
