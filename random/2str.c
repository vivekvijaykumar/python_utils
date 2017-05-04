#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
Given p

while (p/2) {
    scanf the pair of strings
    process smaller string and to save occurances
    process larger string and evalaute the presence
    report result
    memset the input arrays and also clear the occurance cache
}
*/

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int p = 0, i = 0, k = 0;
    scanf("%d", &p);
    char str1[100000] = {0};
    char str2[100000] = {0};
    char occ[26] = {0};
    char result[10][4] = {{0}};

    while(i < p) {
        char flag = 'f';
        memset(occ, 0, sizeof(occ));
        scanf("%s\n%s", str1,str2);
        int sum = 0;
        for(int j=0; j<strlen(str1); j++) {
            if(occ[(int) (str1[j]-'a')] == 0)
                sum += 1;

            occ[(int) (str1[j]-'a')] = 1;
            if(sum == 26)
                break;
        }

        for(int j=0; j<strlen(str2); j++) {
            if (occ[(int) (str2[j] - 'a')] == 1) {
                flag = 't';
                break;
            }
        }
        if(flag == 't')
            memcpy(result[k],"YES", strlen("YES"));
        else
            memcpy(result[k],"NO", strlen("NO"));
        k++;
        i++;
    }

    for(int j=0; j<k; j++)
        printf("%s\n",result[j]);
    return 0;
}
