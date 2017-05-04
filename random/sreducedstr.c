#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[100] = {0};
    scanf("%s", str);
    int i,sw;
    for(i=0,sw=-1; i<strlen(str);) {
        if(str[i] == str[i+1]) {
            i+=2;
            continue;
        } else {
            if((i!=sw) && sw >=0) {
                if(str[sw] == str[i])
                    sw--;
                else
                    str[++sw] = str[i];                
            } else {
                str[++sw] = str[i];
            }      
        }
        i++;
    }
    str[sw+1]='\0';
    if(sw < 0)
        printf("Empty String\n");
    else 
        printf("%s\n",str);
    
    return 0;
}

