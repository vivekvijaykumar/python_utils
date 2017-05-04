#include <stdio.h>
#include <stdlib.h>


int main()
{
   char str[100]  = {0};
   str[0]='\0';

   snprintf(str, sizeof("hello world"), "hello world hello world");
   printf("%s\n", str);


   FILE *f = fopen("/tmp/test","r");
   
   while( fgets(str,100,f)  != NULL) {
           printf(">>> %s\n", str);
   }
   fclose(f);
   return 0;
}
