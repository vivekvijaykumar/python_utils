#!/usr/bin/python

tree1=[]
tree2=[]

def findleaf(l1):
    global tree1
    if(len(l1)==1):
        return l1[0]
    if(len(l1)==0):
        return -1
    temp = l1[0]
    for i in range(1,len(l1)):
        if(temp < l1[i]):
            print l1[1:i] , l1[i:]
            l = findleaf(l1[1:i])
            r = findleaf(l1[i:])
            if(l != -1):
                tree1.append(l)
            if(r != -1):
                tree2.append(r)
            else:
                break
    return -1



