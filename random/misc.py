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
        if(int(inp) != 0):
            return 1
        else:
            return -1
    elif(len(inp) == 2):
        if(int(inp) <=26):
            return 2
        else:
            return 1

    #count += encode(inp[0:1]) + encode(inp[0:2]) + encode(
    count += encode(inp[1:]) + encode(inp[2:])
    return count


# Python program to print all permutations with
# duplicates allowed

def toString(List):
    return ''.join(List)

# Function to print permutations of string
# This function takes three parameters:
# 1. String
# 2. Starting index of the string
# 3. Ending index of the string.
string = "ABC"
n = len(string)
a = list(string)
positions = list(string)
def permute(a, l, r):
    if l==r:
        print toString(a)
    else:
        for i in xrange(l,r+1):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, r)
            a[l], a[i] = a[i], a[l] # backtrack

# Driver program to test the above function
permute(a, 0, n-1)
