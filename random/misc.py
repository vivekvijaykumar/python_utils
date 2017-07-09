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



def countSteps(n):
    if(n < 0 ):
        return 0
    if(n == 0):
        return 1
    return countSteps(n-1) + countSteps(n-2) + countSteps(n-3)

def countSteps2(n, l):
    if(n <= 0 ):
        return 0

    if(n == 1):
        return 1
    elif(n == 2):
        return 2
    elif(n == 3):
        return 3

    l[n] = countSteps2(n-1, l) + countSteps2(n-2, l) + countSteps2(n-3, l)
    return l[n]

def powr(x,y):
    if(y==0):
        return 1
    temp = powr(x,y/2)
    if(y%2):
        return temp * temp * x
    return temp*temp

def pow(x,y):
    prod = 1;
    while(y):
        if(y and 0x1):
            print "mutliply1"
            prod *= x
        y >>= 1
        x *= x
        print "mutliply2"
    return prod



def ispermute(str1, str2):
    dic = {}

    if(len(str1) != len(str2)):
        return False

    for char in str1:
        if dic.has_key(char):
            dic.update({char: dic[char]+1})
        else:
            dic.update({char:1})

    for char in str2:
        if dic.has_key(char):
            val = dic[char]-1
            if val == 0:
                dic.pop(char)

    if len(dic.keys()):
        return False

    return True


#facebook
def powerset(input_list):
    l = len(input_list)
    mask = 1<<l
    output_list=[]
    i=0
    for i in range(mask):
        j=0
        temp_list = []
        while (i):
            if(i & 0x1):
                temp_list.append(input_list[j])
            j += 1
            i >>= 1
        output_list.append(temp_list)
    return output_list


#rubrik
def str_divide(num1, num2):
    rlist=[]
    qlist=[]

    quotient = num1 / num2
    reminder = num1 % num2
    qlist.append(quotient)

    if(reminder == 0):
        return str(quotient)
    else:
        #loop for new quotients.
        while(True):
            if(reminder < num2):
                num1 = reminder * 10
                quotient = num1 / num2
                reminder = num1 % num2
                qlist.append(quotient)
                if(reminder == 0):
                    #we know its done at this point
                    break
                elif(reminder in rlist):
                    break
                else:
                    rlist.append(reminder)

        print qlist, rlist
        out_str=""
        if(reminder == 0):
            out_str = str(qlist[0]) + "." + str(qlist[1:])
        else:
            #reminder is valid and it repeated
            #find the position of repeatition and then move so
            #many places on the qlist and mark it repeated.
            pos = 0
            for x in rlist:
                if(reminder == x):
                    break
                pos += 1
            if(pos == 0):
                out_str = str(qlist[0]) + "." + "(" + str(qlist[pos+1:]) + ")"
            else:
                out_str = str(qlist[0]) + "." + str(qlist[1:pos]) + "(" + str(qlist[pos:]) + ")"

        return out_str

#longest common string
def lcs(input_str):
    """
    go over string and keep track of the char occurences for a given
    window under consideration. If there is a repeatition in the set
    then clear the set and start the sliding window fresh from the
    current location and compare the lengths of previous best maximum
    window length and modify it accordingly.
    """

    maxlen = 0
    currlen = 0
    window = set()
    start = 0
    end = 0
    substr = ""
    for i in range(len(input_str)):
        if (input_str[i] in window):
            maxlen = max(maxlen, currlen)
            window.clear()
            window.add(input_str[i])
            currlen = 1
            substr = input_str[start:end+1]
            start = i
            end = i
            print maxlen, substr, window
        else:
            window.add(input_str[i])
            currlen += 1
            end += 1

    if(maxlen < currlen):
        maxlen = currlen
        substr = input_str[start:end+1]

    return substr

#rearrange a number with same digits to get maximum number
# 62832  -- 86322
def rearrange(num):
    """
    1) first get individual numbers and seprate them
    2) sort the individual numbers in descending order
    3) merge them together to get the number you need.
    """
    l=[]
    while(num):
        l.append(num%10)
        num /= 10

    l.sort()
    print l

    num = 0
    base=1
    for i in l:
        num += (i*base)
        base *= 10

    print num


def max_sum(array, i):
    if (i==0):
        return array[0]
    if (i==1):
        return max(array[0], array[1])

    return max(max_sum(array, i-1), array[i] + max_sum(array, i-2))


