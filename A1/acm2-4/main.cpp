#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int a,b,d,e,f,g,h;
    long long c;
    int s1[100];
    int s2[100];
    char s[100];
    scanf("%d",&a);
        for(int i=0;i<a;i++)
        {
            scanf("%d %d",&b,&c);
            long long sum(int num1);
            printf("%lld\n",sum(c-b));
        }
    return 0;
}

long long sum(int num1)
{
    long long s[50]={1,1};
        for(int i=2;i<=num1;i++)
        {
            s[i]=s[i-1]+s[i-2];
        }
     return s[num1];

}
