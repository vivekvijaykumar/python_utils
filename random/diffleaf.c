#include <stdio.h>
#include <stdlib.h>

#if 0
int findleaf2(int a[], int s, int e)
{
    if(s==e) {
        return a[s];
    }
    int l1,r1,l2,r2,i;

    l1=r1=l2=r2=-1;

    for(i=s+1; i<=e; i++) {
        if(a[s] < a[i]) {
            l1 = findleaf(a,s+1,i-1);
            r1 = findleaf(a,i,e,);
            if(l1 == -1 || r1 == -1)
                break;
        }
    }
    for(int i=s2+1; i<=e2; i++) {
        if(a2[s2] < a2[i]) {
            l2++;
            l2 = findleaf(a2,s2+1,i-1, ll2);
            r2 = findleaf(a2,i,e2, ll2);
            if(l2 == -1 || r2 == -1)
                break;
        }
    }

    printf("Leaf @level:%d [%d:%d  ---  %d:%d]\n", ll1,l1,r1,l2,r2);
    return -1;
}
#endif

int findleaf(int a[], int s, int e, int level)
{
    if(s==e) {
        return a[s];
    }
    for(int i=s+1; i<=e; i++) {
        if(a[s] < a[i]) {
            level++;
            int l = findleaf(a,s+1,i-1, level);
            int r = findleaf(a,i,e, level);
            if(l != -1)
                printf("Leaf @level:%d[%d]\n", level,l);
            if(r != -1)
                printf("Leaf @level:%d[%d]\n", level,r);
            else
                break;
        }
    }
    return -1;
}



int main()
{
    int a[]={5,3,2,4,8,7,9};
    findleaf(a,0,6,0);
    printf("==================\n");
    int a1[]={5,3,2,4,8};
    findleaf(a1,0,4,0);
    return 0;
}
