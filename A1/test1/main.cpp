//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//int main()
//{
//    int b=b[3][4];
//    int (*p)[4]=b; //Êı×éÖ¸Õë row
//    return 0;
//}

#include<stdio.h>
int main()
{  long int n;
   int d,num,m=9,t=1;
   int c=1;
   num=0;
   scanf("%d %d",&n,&d);
   do
   { t*=10;
    if((n%t-n%(t/10))/(t/10)==d)
    {
        num+=1;
        printf(" %d",c);
    }
    c++;
      m=(n%t-n%(t/10))/(t/10)<m?(n%t-n%(t/10))/(t/10):m;


   }while(t*10<n);
   printf("num=%d, min=%d",num,m);
   return 0;
}
