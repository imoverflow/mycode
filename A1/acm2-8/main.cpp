#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    int a;
    long b,sum,t;
    int f;
    long s[500];
    while(scanf("%d",&a)!=EOF)
    {
        for(int i=0;i<a;i++)
        {
            scanf("%ld",&b);
            s[i]=b;
        }
        sort(s,s+a);
        long minmul(long num1,long num2);
        t=s[0];
        for(int j=1;j<a;j++)
        {
            if(t%s[j]!=0)
                t=minmul(t,s[j]);
        }
        printf("%ld\n",t);
    }
    return 0;
}
long minmul(long num1,long num2)
{
    if(num1>num2)
    {
        for(long i=num2;;i++)
        {
            if(i%num1==0&&i%num2==0)
                return i;
        }
    }else
    {
        for(long i=num1;;i++)
        {
            if(i%num1==0&&i%num2==0)
                return i;
        }
    }
}
