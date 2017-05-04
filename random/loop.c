#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int child;

    child = fork();
    if(child == 0 ) {
        printf("Inside child \n");
        /* in child */
        while(1) {
            sleep(1);
        }
    } else if(child == -1) {
        /* error */
        printf("Error while forking \n");
    } else {
        /* in parent */
       printf("Inside Parent \n"); 
       while(1) {
           sleep(1);
       }
    }

    return 0;
}
