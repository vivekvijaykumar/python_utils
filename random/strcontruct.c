#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Input N 
scanf n lines
output cost


while(n)
scanf str
build dictionary of lower case with count.
for char in str:
check in dictionary and if not add cost 
if present do a free copy

stop bulding dictionary if we already have all 26 english alphabets
*/


int main(){
	int sum = 0, cost = 0, n = 0;
	char str[100000] = {0};
    int result[5] = {0};
	int dict[26] = {0};	
    scanf("%d",&n);
    	
    for(int a0 = 0; a0 < n; a0++){
        memset(dict,0,sizeof(dict));
        cost = sum = 0;
        scanf("%s",str);
#if 0
		for(int i=0; i<strlen(str); i++) {
            if(!dict[(int) (str[i]-'a')]) {
                cost++;
                sum++;
                dict[(int) (str[i]-'a')]=1; 
            }

            /* we have seen all 26 characters in the input string already */
            if(sum == 26)
                break;
		}
#else
        for(int i=0, j=strlen(str)-1; i<strlen(str)/2; i++,j--) {
            if(!dict[(int) (str[i]-'a')]) {
                cost++;
                sum++;
                dict[(int) (str[i]-'a')]=1; 
            } 
            if(!dict[(int) (str[j]-'a')]) {
                cost++;
                sum++;
                dict[(int) (str[j]-'a')]=1; 
            }

            /* we have seen all 26 characters in the input string already */
            if(sum == 26)
                break;
        }
#endif

        result[a0] = cost;
    }
    for (int a0=0;a0<n;a0++)
        printf("%d\n",result[a0]);
    return 0;
}
