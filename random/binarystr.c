#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int main(){
    int n; 
    scanf("%d",&n);
    char* B = (char *)malloc(10240 * sizeof(char));
    scanf("%s",B);
    char test[3]="010";
    int count=0,i=0,j=0;
    while (i < n) {
       if(B[i] == test[j]) {
           j++;
           i++;
           if(j==3) {
               j=0; 
               count++;
           }
       } else {
           if(j>0)
               i++;
           j=0;
       } 
    }
    printf("%d", count);
        
    return 0;
}

