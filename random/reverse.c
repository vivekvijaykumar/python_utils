#include <stdio.h>

void
reverse_print(int a) 
{
    if(a==0)
        return;

    printf("%d", a%10);
    reverse_print(a/10);
}

int 
main() 
{
    int a=0;
    scanf("%d", &a);
    if(a<0) {
        printf("-");
        a=a*(-1);
    }
    reverse_print(a);
    printf("\n");
}
