#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    //freopen("a.txt","r",stdin);
    long long a,b,c;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        long long x=0,v=1;
        if(a==1&&b==1)
        {
            printf("Yes\n");
            continue;
        }
        x=gcd(a,b);
        if(x==1)
        {
            printf("No\n");
            continue;
        }
        while(a%x==0)
        {
            a/=x;
        }
        while(b%x==0)
        {
            b/=x;
        }
//        v=gcd(x,a);
//        while(a%v==0&&v!=1)
//        {
//            a/=v;
//        }
//        v=gcd(x,b);
//        while(b%v==0&&v!=1)
//        {
//            b/=v;
//        }
        while((v=gcd(x,a))!=1)
        {
            a/=v;
        }
        while((v=gcd(x,b))!=1)
        {
            b/=v;
        }
        if(x%a==0&&x%b==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
