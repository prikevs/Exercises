n = int(raw_input())

array = []
a = 1
b = 1
if n > 1:
    array.append(a)
    array.append(b)
    c = a + b
    while c <= n:
        array.append(c)
        a = b
        b = c
        c = a + b
    print "The array is ",array
    ave = 0.0
    for x in array:
        ave += x * 1.0
    ave = ave / len(array)
    print "The average is ",ave

    var = 0.0
    for x in array:
        var += (x-ave)*(x-ave)
    var /= len(array)
    print "The var is",var

    if len(array) % 2 == 1:
        print "The mid is",array[len(array)/2]
    else:
        print "The mid is",(array[len(array)/2-1] + array[len(array)/2])/2.0
