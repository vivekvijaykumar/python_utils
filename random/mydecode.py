#!/usr/bin/python

'''
evaluate expressions of this sort "3[a2[bd]g4[ef]h]"
1) append i in input to list
2) if i == ']' pop elements till we consume '[' and the next number
3) compute the new string of characters and push it back into the stack
4) repeat till stack has only 1 item
'''

stack=[]
def decode(inputstr):
    global stack
    for i in inputstr:
        if(i != ']'):
            stack.append(i)
            print stack
        else:
            substr=""
            while True:
                char=stack.pop()
                if(char == '['):
                    break
                substr=char+substr

            char = stack.pop()
            '''
            check if char is a int multiplication factor and if so
            process substr and append back to stack

            if not simply append back the char and substr
            '''
            try:
                int(char)
                substr = int(char) * substr
            except ValueError:
                substr = char+substr

            stack.append(substr)

    stack="".join(stack)



