#include <iostream>
#include <stdio.h>
using namespace std;
long long mod_pow(long long x,long long n,long long mod)
{
    long long res=1;
    while(n>0)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
long long qian(long long x,long long n,long long mod)
{
    long long res=1;
    while(n>0)
    {
        if(n%2)
        {
            if(res>mod)
                res/=mod;
            res=res*x;
        }
        if(x>mod)
            x=x/mod;
        x=x*x;
        n>>=1;
    }
    while(res>1000)
    {
        res/=10;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        printf("Case %d: %lld %lld\n",i,qian(n,k,1000),mod_pow(n,k,1000));
    }
    return 0;
}
