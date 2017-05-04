#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int lonelyinteger(int a_size, int* a) {
    int local_a[100] = {0};

    if(!a) {
        printf("Input Array empty \n");
        return -1;
    }

    if(a_size <= 0) {
        printf("Input Array empty \n");
        return -1;
    }
    
    for (int i=0; i<(a_size); i++) {
        if(local_a[a[i]] != 1) {
            local_a[a[i]] = 1;
        } else {
            local_a[a[i]] = 2;
        }
    }

    for (int i=0; i<100; i++) {
        if(local_a[i] == 1)
            return i;
    }

    return 0;
}


int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d\n", res);
    
    return 0;
}

