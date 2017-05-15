#include <stdio.h>
#include <stdlib.h>

void group(int *a, int len)
{
    //1. left ptr starts from i=0
    //2. right ptr starts from i=(size-1)
    //3. check 
    //      if value @left_ptr is zero and if so
    //   value at @right_ptr is non-zero, then swap
    //   the values.  left_ptr++, right_ptr--
    //   .
    //      if value@left_ptr is zero and @right_ptr 
    //   is also zero, move right_ptr--o
    //      
    //      if value@left_ptr is non-zero and @right_ptr
    //   is zero, right_ptr--
    //
    //   repeat 3 till left_ptr<right_ptr
    if(len==0)
        return;

    unsigned int left_ptr, right_ptr;
    for(left_ptr=0, right_ptr=len-1; left_ptr<right_ptr; ) {
        if(a[left_ptr]!=0 && a[right_ptr]!=0) {
            left_ptr++; 
        } else if(a[left_ptr]==0 && a[right_ptr]!=0) {
            a[left_ptr] = a[right_ptr];
            a[right_ptr] = 0;
            left_ptr++, right_ptr--;
        } else if(a[left_ptr] !=0 && a[right_ptr]==0) {
            right_ptr--;
            left_ptr++;
        } else if(a[left_ptr] == 0 && a[right_ptr]==0) {
            right_ptr--;
        }
    }
    return;
}

int main()
{
    //1. init input array
    int array[] = {1,0,0,3,0,5,6,7,0,8,0,9,0,0};
    unsigned int i=0;

    printf("%15s","Original:");
    for(i=0; i<sizeof(array)/sizeof(int); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    group(array, sizeof(array)/sizeof(int));
    printf("%15s","Regrouped:");
    for(i=0; i<sizeof(array)/sizeof(int); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}
