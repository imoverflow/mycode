#include <stdio.h>
#include <stdlib.h>

main()
{
   FILE *fl;
   char s[100];
   long count;
   long sum;
   printf("sum:please input the address of the file:");
   scanf("%s",s);
   if((fl=fopen(s,"r"))==NULL)
   {
       printf("fail to open the file");
       exit(0);
   }else
   {
       printf("success\n");
       while(fscanf(fl,"%ld",&count)!=EOF)
       {
           long nsum(int n);
            sum=nsum(count);
            printf("%d\n",sum);
            printf("\n");
       }
   }
}

long nsum(int n)
{
    long sum;
    sum=0.5*n*(n+1);
    return sum;
}
