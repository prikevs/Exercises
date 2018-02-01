#!/usr/bin/env python2.7

def judge(edge):
    edge.sort()
    [a, b, c] = edge
    if a + b <= c:
        return "not a triangle"
    if a == b and b == c:
        return "equilateral triangle"
    if a == b or b == c:
        if a * a + b * b == c * c:
            return "isosceles right triangle"
        return "isosceles triangle"
    if a * a + b * b == c * c:
        return "right triangle"
    return "normal triangle"

def main():
    s = raw_input("input three edges of a triangle, split by a space: ")
    ss = s.split(" ")
    edge = []
    for i in ss:
        edge.append(float(i))
    print judge(edge)

if __name__ == '__main__':
    main()
