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
    scanf("%d",&e);
        for(int i=0;i<e;i++)
        {
            scanf("%d %d",&b,&d);
            c=0;
            long long sum(int a,int b);
            for(int j=d-b;j>=0;j--)
            {
                for(int k=d-b;k>=0;k--)
                {
                    if((j+2*k)==d-b)
                    {
                        if(j!=0&&k!=0)
                        c+=sum(j,k);
                        else
                            c++;
                    }
                }
            }
            printf("%lld\n",c);
        }
    return 0;
}

long long sum(int a,int b)
{
    int t;
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    long long su=0;
    int k=0;
    long long c,d,e;
    c=d=e=1;
    for(int i=a+b;i>=1;i--)
    {
        d*=i;
        if(k==a-1)
            break;
            k++;
    }
    for(int j=1;j<=a;j++)
    {
        e*=j;
    }
    su=d/e;
    return su;
}
