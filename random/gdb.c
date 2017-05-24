#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a_s{
    char a;
    int b;
    long long c;
    long long d;
    char e;
};

int main()
{
    struct a_s *abc=malloc(sizeof(struct a_s));
    memset(abc,0,sizeof(struct a_s));
    abc->a='a';
    abc->b=1234567;
    abc->c=0xDEADL;
    abc->d=0xBEEF;
    abc->e='b';
    while(1) {}
    return 0;
}
