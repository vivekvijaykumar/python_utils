#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int k = 0;
    
    scanf("%d %d", &n, &k);

    int *a = malloc(sizeof(int)* n);
    for (int a_i=0; a_i<n; a_i++)
        scanf("%d", &a[a_i]);

	for(int i=0, j=0; i<n-k && j<k; i++, j++)
		a[i+k] = a[j];

    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
	return 0;
}
