#!/usr/bin/python

opl = []
def addnum(l, num):
    global opl
    carry = num
    for i in reversed(range(len(l))):
        total = l[i] + carry
        numi = total % 10
        carry = total / 10
        opl.append(numi)

    while (carry):
        opl.append(carry%10)
        carry = carry / 10

    opl.reverse()
