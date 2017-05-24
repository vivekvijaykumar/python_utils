#!/usr/bin/python

l={}
g=[]
def path(paths, steps):
    global l
    if(steps > 0):
        path(paths+str(1), steps-1)
        path(paths+str(2), steps-2)
    elif(steps == 0):
        if l.has_key(paths) == False:
            l.update({paths:1})
            print paths

    return paths
