#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int randomize(int array[], int len)
{
    int max = 0, count = 0, i = 0;

    if(len)
        max = array[0];
    else 
        return 0;

    //Find the MAX 
    for(i=0; i<len; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    //Find the count of MAX occurences
    for(i=0; i<len; i++) {
        if(array[i] == max)
            count++;
    }
    //Figure out the random index
    int random = rand() % count;
    //printf("MAX, count %d:%d randmon:%d\n", max, count,random);
    count = 0;
    for(i=0; i<len; i++) {
        if((array[i] == max) && (count == random)) {
            //printf("Picked i:%d\n", i);
            return i;
        } else if(array[i] == max) {
            count++;
        }
    }
    
    return 0;
}


int main()
{
    int array[] = {1,-2,0,6,2,-4,6,6};

    time_t t;
    srand((unsigned) time(&t));
    for (int i=0; i<100; i++)
        printf("%d : %d\n",i, randomize(array, sizeof(array)/sizeof(int)));
    return 0;
}
