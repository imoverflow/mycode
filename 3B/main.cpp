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
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",mod_pow(a,b,10));
    }

    return 0;
}
