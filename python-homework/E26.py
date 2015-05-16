#!/usr/bin/env python2.7

stra = raw_input("The A string: ")
strb = raw_input("The B string: ")

lena = len(stra)
lenb = len(strb)

dp = [[0 for _ in (strb+' ')] for _ in (stra+' ')]

for j in range(1, lenb + 1):
    dp[0][j] = j

for i in range(1, lena + 1):
    dp[i][0] = i
    for j in range(1, lenb + 1):
        dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + (1 if stra[i-1] != strb[j-1] else 0))


print dp[lena][lenb]
