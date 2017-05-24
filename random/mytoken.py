#!/usr/bin/python

dictionary = {'and': 1, 'bath': 1, 'bed': 1, 'beyond': 1, 'dbath':1}

inp="bedbathandbeyond"

l={}

def tokenize(inp):
    global l
    length=len(inp)
    i=0;
    while (i<length):
        if(l.has_key(inp[:i+1])):
            i += 1
            continue

        if(dictionary.has_key(inp[:i+1])):
            l.update({inp[:i+1]:1})
        i += 1
        tokenize(inp[i:])


l3={}
def tokenize_new(inp):
    global l,l3
    length=len(inp)
    i=0;
    while (i<length):
        if(l.has_key(inp[:i+1])):
            i += 1
            continue

        #print inp[:i+1], inp[i+1:]
        if(dictionary.has_key(inp[:i+1])):
            l.update({inp[:i+1]:1})
            print "HOLA********************"
        i += 1
        tokenize_new(inp[i:])

def tokenize1(inp):
    global l,l3
    for i in range(len(inp)):
        if(l3.has_key(inp[i:])):
            continue

        if(l.has_key(inp[:i+1])):
            continue

        if(dictionary.has_key(inp[:i+1]) and tokenize1(inp[i:])):
            l.update({inp[:i+1]:1})
            print "HoLA"
            return
        l3.update({inp[i:]:1})



#tokenize(inp)
#print l

dictionary2 = {'and': 1, 'bath': 1, 'bed': 1, 'beyond': 1, 'dan':1, 'tabh':1}
dictionary3={}
l2={}

def update_dict():
    global dictionary3,dictionary2
    for key in dictionary2.iterkeys():
        val = str(key)
        key="".join(sorted(key))
        #print key
        if(dictionary3.has_key(key) == False):
            #print key
            dictionary3.update({key:[val]})
        else:
            list_val = dictionary3[key]
            list_val.append(val)
            dictionary3.update({key:list_val})

def token2(inp):
    global l2,l3
    for i in range(len(inp)):
        if(l3.has_key(inp[i:])):
            continue

        key = "".join(sorted(inp[:i+1]))
        if(l2.has_key(key)):
            continue

        if(dictionary3.has_key(key) and token2(inp[i:])):
            l = dictionary3[key]
            l2.update({key:l})
            return
        l3.update({inp[i:]:1})

'''
    while(i<len(inp)):
        key = "".join(sorted(inp[:i+1]))
        if(l2.has_key(key)):
            i += 1
            continue

        if(dictionary3.has_key(key)):
            l = dictionary3[key]
            l2.update({key:l})

        i += 1
        token2(inp[i:])
'''

def tokenize2(inp):
    update_dict()
    token2(inp)
