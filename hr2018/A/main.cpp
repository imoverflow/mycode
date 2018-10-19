#include <iostream>
#include <stdio.h>

using namespace std;
const long long mod=1e9+7;

long long quick(long long x,long long d)
{
    long long ans=1;
    while(d>0)
    {
        if(d&1) ans=ans*x%mod;
        x=x*x%mod;
        d>>=1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=quick(i,d);
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
