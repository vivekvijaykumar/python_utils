#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T=0,i=0;
    scanf("%d", &T);
    char input[T][100000];
    //printf("%d\n", T);
    //printf("\n");

    for(i=0;i<T;i++) {
        scanf("%s\n",input[i]);
        //printf("%d\n", (int) strlen(input[i]));
    }
    
    for(i=0; i<T; i++) {
        int j=0;
        int runctr = 1;
        int compressctr = 0;
        
        //printf(">>%d \n", (int)strlen(input[i]));
        while( j<strlen(input[i]) ) {
            /* 
             * check for last character - previous index would have 
             * taken care of repeat counter. so we can skip that count.
             */
            if(j == (strlen(input[i])-1)) {
                compressctr = compressctr + runctr-1;
                runctr = 1;
                break;
            } 
            // check for continuous same chars
            if(input[i][j]==input[i][j+1]) {
                //printf("[%d]%d ", j, runctr);
                runctr++;
                j++;               
            } else {
                // if not update the compress factor 
                 //printf("[%d]%d ", j,runctr);
                if(runctr == 1 )
                    j++;
                else if(runctr > 1)
                    compressctr = compressctr + runctr-1;

                runctr = 1;
            }
        }
        //printf("\nrunctr:%d\n",runctr);
        if(runctr > 1)
            runctr = runctr - 1 ;
        //compressctr = compressctr + runctr;
        printf("%d\n", compressctr);
    }
    //#endif
    return 0;
}

