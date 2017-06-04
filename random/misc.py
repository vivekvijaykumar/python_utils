#!/usr/bin/python

#count consecutive ones in all numbers less than equal to N
#in their binary representation format.
def countOnes(N):
    if(N < 0):
        return 0;

    count = 0
    while(N >= 0):
        if(not (N & (N-1))):
            count += 1
        N -= 1
    return count




dictionary = {'bed':1, 'bath':1, 'and':1, 'beyond':1}
parse=set()
out=[]
'''
tokenizes only when all the words are segmetable with the
dictionary words. else will not simply pick one or a subset
of workds from inp that may be segmentable
ex: "bedbathandbeyond"   - works
ex: "abcbedcfgbathandbeyond"  - does not work
'''
def tokenize(inp):
    global dictionary,out,parse

    for i in xrange(len(inp)+1):
        key = inp[0:i]
        substr = inp[i:]
        if(substr in parse):
            continue
        else:
            parse.add(substr)
        if(len(key)):
            print key,substr
            if(dictionary.has_key(key) and tokenize(substr)):
                out.append(key)
                return True
    return True


'''
find target sum pairs given a target sum
a) unsorted
b) sorted

to save space one way is to sort the list
to increasing order and then apply a variation
of binary search.
'''
def sum_pairs(l,target):
    a=set()
    k=[]

    if(not len(l)):
        return False

    for i in l:
        if(i in a):
            k.append((i,target-i))
        else:
            a.add(target-i)
    return k

'''
input = 123
a=1
b=2
...
z=26

123 = abc, lc, av = total(3)

'''
def encode(inp):
    count = 0
    if(len(inp) == 1):
        return 1
    elif(len(inp) == 2):
        if(int(inp) <=26):
            return 2
        else:
            return 1

    count += encode(inp[0:1]) + encode(inp[0:2]) + encode(
    return count

