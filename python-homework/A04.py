#!/usr/bin/env python2.7

def getWords(data):
    datas = data.split(' ')
    words = []
    for d in datas:
        if d.isalpha():
            words.append(d)
    return words

def main():
    sentence = raw_input("Please input the sentence:\n")
    words = getWords(sentence)
    num = len(words)
    total = 0
    for word in words:
        total = total + len(word)
    print("%d words in the sentence, the average of the length is %.2f" % (num, total * 1.0 / num))

if __name__ == '__main__':
    main()
