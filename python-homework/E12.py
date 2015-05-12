n = int(raw_input())

if n == 1:
    print 1
elif n == 2:
    print 2
else:
    a = 1
    b = 2
    n -= 2
    while n > 0:
        ans = a + b
        a = b
        b = ans
        n -= 1
    print ans
