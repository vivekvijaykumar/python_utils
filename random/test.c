#include <stdio.h>
#include <stdlib.h>


int** performOps(int A[][4], int m, int n, int *len1, int *len2) {
    int i, j;
    *len1 = m;
    *len2 = n;
    int **B = (int **)malloc((*len1) * sizeof(int *));
    for (i = 0; i < *len1; i++) {
        B[i] = (int *)malloc((*len2) * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            B[i][n - 1 - j] = A[i][j];
        }
    }
    return B;
}

int main()
{
	int A[3][4] = { {1, 2, 3, 4}, 
                  {5, 6, 7, 8}, 
				  {9, 10, 11, 12},
		        };
	int len1, len2;
	int **B = performOps(A, 3, 4, &len1, &len2);
	int i, j;
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			printf("%d ", B[i][j]);
		}
	}

    unsigned int i1=0;
    printf("%u:%x \n", i1, --i1);

}
