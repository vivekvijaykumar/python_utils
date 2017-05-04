#!/usr/bin/python
def insertionSort(ar):
    pos = len(ar)-2;
    val = ar[-1]
    move = pos+1
    print pos,val,move
    while (pos >=0 ):
        if ar[pos] > val:
            ar[move] = ar[pos]
        else:
            break
        pos -= 1
        move -=1
        print str(ar).strip('[').strip(']').replace(',', ' ')
    ar[move] = val
    print str(ar).strip('[').strip(']').replace(',', ' ')
    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar[:m])

