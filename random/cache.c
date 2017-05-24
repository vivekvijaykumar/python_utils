#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define KB 1024
#define MB 1024 * 1024

int main(int argc, char **argv) {
    unsigned int steps = 256 * 1024 * 1024;
    static int arr[20 * 1024 * 1024];
    int lengthMod;
    unsigned int i;
    double timeTaken;
    clock_t start;
    int sizes[] = { 
        1 * KB, 4 * KB, 8 * KB, 16 * KB, 32 * KB, 64 * KB, 128 * KB, 256 * KB,
        512 * KB, 1 * MB, 1.5 * MB, 2 * MB, 2.5 * MB, 3 * MB, 3.5 * MB, 4 * MB, 
        6*MB, 20*MB
    };

    int l2 = 256*KB;
    int l3 = 6*MB;
    int dram = 20*MB;

    int results[sizeof(sizes)/sizeof(int)];
    int s;

#if 1
    // for each size to test for ... 
    for (s = 0; s < sizeof(sizes)/sizeof(int); s++) {
	    lengthMod = sizes[s] - 1;
	    start = clock();
	    for (i = 0; i < steps; i++) {
	        arr[(i * 16) & lengthMod]++;
	    }

	    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("%d, %.12f \n", sizes[s] / 1024, timeTaken);
    }
#else
    start = clock();
    lengthMod = l2 -1;
    for (i = 0; i < steps; i++) {
        arr[(i * 16) & lengthMod]++;
    }

    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("%10s-- %4d, %.12f \n", "L2", l2 / 1024, timeTaken);


    start = clock();
    lengthMod = l3 -1;
    for (i = 0; i < steps; i++) {
        arr[(i * 16) & lengthMod]++;
    }

    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("%10s -- %4d, %.12f \n","L3", l3 / 1024, timeTaken);

    start = clock();
    lengthMod = dram -1;
    for (i = 0; i < steps; i++) {
        arr[(i * 16) & lengthMod]++;
    }

    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("%10s -- %4d, %.12f \n", "DRAM",dram / 1024, timeTaken);
#endif

    return 0;
}

