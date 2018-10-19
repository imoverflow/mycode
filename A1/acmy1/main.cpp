#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
long long powa(long long a,long long b)
{
    long long sum=1;
    if(b==0)
        return 1;
    for(int i=0;i<b;i++)
    {
        sum*=a;
    }
    return sum;
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        long long b,c,d;
        long long cou=0,e,m=0;
        scanf("%lld %lld %lld",&b,&c,&d);
        for(long long j=0;j<=c;j++)
        {
            long long k=powa(d,j);
            if(k>c)
            {
                e=j;
                break;
            }
            if(k>=b&&k<=c&&m==0)
            {
                printf("%lld",k);
                m++;
            }
            else if(k>=b&&k<=c&&m!=0)
                printf(" %lld",k);
            else
                cou++;
        }
        if(cou==e)
            printf("-1\n");
        else
            printf("\n");
    }
    return 0;
}
