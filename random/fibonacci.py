#!/usr/bin/python

'''
1) find max number in input l to find till what point
we shud generate fibonacci series

2) now generate fibonacci series till less than Max and
put them in a set

3) now go over the list of numbers again and pick the number
which are part of the set and retrun them
'''
def fib(l):
    a=set()
    k=[]
    if(len(l) == 0):
        return k

    mi=0
    for i in l:
        mi = max(mi,i)

    fib1=1
    fib2=1

    a.add(fib1)
    a.add(fib2)

    while (True):
        fib = fib1 + fib2
        if(fib > mi):
            break
        fib1 = fib2
        fib2 = fib
        a.add(fib)

    for i in l:
        if i in a:
            k.append(i)

    return k
