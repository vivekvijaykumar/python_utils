#include <stdio.h>

int main()
{
    int arr[]={10,3,8,20,22,47,49,52};

    int len = sizeof(arr)/sizeof(int);

    int i=0,min=0,max=0,diff=0;
    
    min = max = arr[0];
    for(i=1; i<len; i++) {
        if(arr[i] > max) {
            int tmp_diff = arr[i] - min;
            if(tmp_diff > diff)
                diff = tmp_diff;
            max = arr[i];
        } else if(arr[i] < min) {
            min = arr[i];
            max = arr[i];
        }
    }

    printf("Max diff %d \n", diff);
    return 0;
}
