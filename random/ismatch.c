#include <stdio.h>
#include <stdlib.h>

int ismatch(char *s, int lens, char *p, int lenp)
{
    int i ,j;
    i=j=0;
    for(i=0,j=0; i<lens && j<lenp; ) {
        char prev = *s;
        if(*s == *p) {
            i++,j++;
            s++,p++;
        } else if(*p=='*') {
           if(prev == *s) {
               i++;
               prev = *s;
               s++;
           } else {
               p++;
               j++;
           }
        } else {
            break;
        }
    }
	
    if(j==lenp || i==lens)
        return 1;
    else
        return 0;
}


int main()
{
	printf("ismatch %s %s : %d\n", "aa", "aa", ismatch("aa",2,"aa",2));
	printf("ismatch %s %s : %d\n", "aa", "a", ismatch("aa",2,"aa",1));
	printf("ismatch %s %s : %d\n", "aaa", "aa", ismatch("aa",3, "aa",2));
	printf("ismatch %s %s : %d\n", "aa", "a*", ismatch("aa",2,"a*",2)); 
	printf("ismatch %s %s : %d\n","aa", "a*", ismatch("aa", 2, "*", 1)); //true
	printf("ismatch %s %s : %d\n","a", "b*a", ismatch("a", 1, "b*a", 3)); //true
	printf("ismatch %s %s : %d\n","a", "a*a", ismatch("a", 1, "a*a", 3)); //true
	printf("ismatch %s %s : %d\n","a", "b*a*a", ismatch("a", 1, "b*a*a", 3)); //true 
	printf("ismatch %s %s : %d\n","a", "aab", ismatch("aab", 3, "c*a*b", 5)); //true
	printf("ismatch %s %s : %d\n","ccccccaaab", "c*a*b", ismatch("ccccccaaab", 10, "c*a*b", 5)); //true
	printf("ismatch : %d\n",ismatch("ccccccb",7, "c*a*b",5)); //true
	printf("ismatch : %d\n",ismatch("bz", 2, "c*a*bz", 6)); //true
	printf("ismatch : %d\n",ismatch("ccccb", 5, "w*c*a*b", 7)); //true
	printf("ismatch : %d\n",ismatch("wz",2, "w*c*a*b",7)); //false
   	return 0;
}
