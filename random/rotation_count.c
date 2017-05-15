#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0
    if(start > end)
        return 0;

    if(start == end)
        return start;

    int mid = start + (end - start)/2;

    if(mid < end && array[mid+1] < array[mid])
        return mid+1;
    if(mid > start && array[mid] < array[mid-1])
        return mid;

    if(array[end] > array[mid])
        return rotationc(array, start, end-1);

    return rotationc(array,mid+1, end);
#endif

int rotationc(int array[], int start, int end) 
{
    int m = start + (end - start)/2;

    if (start == m) {
        if(array[m+1] < array[m]) {
            return (m+1);
        } else if (array[m+1] == array[m]) {
            return m;
        }else {
            return 0;
        }
    }

    if(array[m] < array[start])
        return rotationc(array, start, m);
    else
        return rotationc(array, m, end);
}

/*
 * 1) words are in lower case 
 */
int word(char words[][15], int start, int end)
{
    int m = start + (end-start)/2;

    if(start == m) {
        int rc = strcmp(words[m+1],words[m]);
        printf("%s:%s  %d \n", words[m+1], words[m], rc);
        if(!rc)
            return m;
        else if(rc < 0)
            return m+1;
        else 
            return 0;
        }

    if((words[m][0]-'a') < (words[start][0]-'a'))
        return word(words, start, m);
    
    return word(words, m, end);
}


int main()
{
    //1. input array
    int array1[] = {15, 18, 2, 3, 6, 12};
    int array2[] = {7, 9, 11, 12, 5};
    int array3[] = {7, 9, 11, 12, 15};
    int array4[] = {4,5,6,7,8,9,10,11,12,0,1,2,3};

    //2. init vars
    unsigned int start,end;

    start = 0;

    end = (sizeof(array1) / sizeof(int));
    end--;
    printf("Rotation @ %d\n", rotationc(array1, start, end));

    end = (sizeof(array2) / sizeof(int));
    end--;
    printf("Rotation @ %d\n", rotationc(array2, start, end));

    end = (sizeof(array3) / sizeof(int));
    end--;
    printf("Rotation @ %d\n", rotationc(array3, start, end));

    end = (sizeof(array4) / sizeof(int));
    end--;
    printf("Rotation @ %d\n", rotationc(array4, start, end));

    char words[][15] = {
      "ptolemaic",
      "retrograde",
      "supplant",
      "undulate",
      "xenoepist",
      "asomptote", // <-- rotates here!
      "asymptote", // <-- rotates here!
      "babka",
      "banoffee",
      "engender",
      "karpatka",
      "othellolagkage",
    };

    end = 12;
    end--;
    printf("Rotation @ %d\n", word(words, start, end));
}
