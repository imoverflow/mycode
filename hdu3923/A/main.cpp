#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long quick(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    int t,n,m;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=quick(m,__gcd(n,i));
        }
        if(n&1) ans+=n*quick(m,n/2+1);
        else ans+=n/2*quick(m,n/2)+n/2*quick(m,n/2+1);
        ans%=mod;
        ans=ans*quick(2*n,mod-2)%mod;
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
