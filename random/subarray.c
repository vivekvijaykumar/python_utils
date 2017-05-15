#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1.Given array
    //int array[] = {2,-1,4,3,-2,-6,8};
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    //int array[] = {2,-1,4,3,-2,-6,8};
    //int array[] = {2,-3,4,3,-2,-6,8};

    //2.Vars
    unsigned int items = sizeof(array)/sizeof(int);
    unsigned int i, beg, end;
    i=beg=end=0;
    int maxs = 0;
    int sum = 0;

    //3.Init vars
    maxs = sum = array[0];

    //4.Loop through and find the max subarray sum
    for(i=1; i<items; i++) {
        
        //5.compute sum @[i] and compare with the item iteself
        //5a. beg = i if(a[i] is larger)
        //    beg = "no_change" if(a[i] is smaller)
        int news = sum+array[i];
        int curr = array[i];
        if (curr > news) {
            sum = curr;
            beg = i;
        } else {
            sum = news;
        }
        
        //6.compte max sum sofar using sum @[i] and maxs 
        //6a. end = i if(sum + a[i] is larger)
        //    end = no_change (if still old maxs is larger)
        if (sum > maxs) {
            end = i;
            maxs = sum;
        }
        printf("[%3d] : %3d : %3d [%d::%d]\n", i, sum, maxs, beg, end); 
    }

    printf("Max subarray sum is:%3d between %d-%d\n", maxs, beg, end);
    return 0;
}
