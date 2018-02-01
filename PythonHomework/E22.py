#!/usr/bin/env python2.7

def getprime(n):
    prime = []
    mark = [False] * (n + 1)
    for i in range(2, n + 1):
        if mark[i] == False:
            prime.append(i)
        j = 0
        while j < len(prime) and prime[j] * i < n + 1:
            mark[i * prime[j]] = True
            if i % prime[j] == 0:
                break
            j = j + 1
    return prime

def main():
    n = int(raw_input("Please input n:"))
    prime = getprime(n)
    print(prime) 

if __name__ == '__main__':
    main()
