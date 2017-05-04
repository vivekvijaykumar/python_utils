#include <stdio.h>

int main()
{
    int a1[10] = {0};
    int a2[10] = {0};


    int i;
    for(i=0; i<10; i++) {
        if(i%2)
            a1[i] = i;
        else 
            a2[i] = i;
    }
    for(i=0; i<10; i++) {
        printf("[%d]%d,%d:%d ",i,a1[i],a2[i],a1[i]&a2[i]);
    }
    printf("\n");
}
