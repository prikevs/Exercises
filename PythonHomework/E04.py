#!/usr/bin/env python2.7

import random

def encrypt():
    plaintext = raw_input("Please input a string to be encrypted:")
    seed = random.randint(1, 65536)
    random.seed(seed)
    cipher = ''
    for i in plaintext:
        cipher = cipher + chr(ord(i) ^ random.randint(1, 127))
    return (plaintext, seed, cipher)

def decrypt(seed, cipher):
    random.seed(seed)
    plaintext = ''
    for i in cipher:
        plaintext = plaintext + chr(ord(i) ^ random.randint(1, 127))
    return plaintext


def main():
    (plain1, seed, cipher) = encrypt()
    print("Plain text:       %s" % (plain1))
    print("Seed:             %d" % (seed))
    print("After encryption: %s" % (cipher))
    plain2 = decrypt(seed, cipher)
    print("After decryption: %s" % (plain2))

if __name__ == '__main__':
    main()
