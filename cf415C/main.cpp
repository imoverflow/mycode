#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
const long long mod=1e9+7;
long long s[500005];
long long dp[500005];
long long mod_pow(long long x,long long n)
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
    }
    sort(s,s+n);
    memset(dp,0,sizeof dp);
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        ans=(ans+s[i]*(mod_pow(2,i)-1))%mod;
        ans=(ans-s[i]*(mod_pow(2,n-i-1)-1))%mod;
    }
    printf("%lld",ans%mod);
    return 0;
}
