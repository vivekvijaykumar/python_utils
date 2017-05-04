#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char c;
    printf("hackerrank");
    do {
        c=getchar();
        putchar(c);
    } while (c!='\n');
    printf("\n");
    return 0;
}
