#include <stdio.h>

int bulbs(int* A, int n1) {
    int i=0;
    int invalidate=0;
    int count=0;
    for(i=0; i<n1; i++) {
        if(invalidate) {
            if(!(A[i] ^ 0x1)) {
                printf("%d %d\n", A[i], A[i] ^ 0x1);
                count++;
                invalidate ^= 1;
            }
            continue;
        } 
        if(!A[i]) {
            count++;
            invalidate ^= 0x1;
            printf("Invalidate %d\n", invalidate);
        }
    }
    
    return count;
}

int main()
{
	int array[] = {0,0,0,0};
    printf("%d\n", bulbs(array,4));
}
