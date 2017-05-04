#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
 
int main()
{
     
    int flag = 0;
    char *str = malloc(sizeof(char) * 100000);
    scanf("%s", str);
    
    int dict[26] = {0};
    int i;
    printf("\n");
    for(i=0; i<strlen(str);i++) {
        dict[str[i]-'a']++;
        if((dict[str[i]-'a'] % 2)==0)
            dict[str[i]-'a']=0;
    }
    printf("\n");
    for(i=0; i<26; i++) {
        flag += dict[i];
    }
    printf("\n");
    

    if (flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}


