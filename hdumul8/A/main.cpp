#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long dp[100010];
const long long mod=998244353;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,0,sizeof dp);
        long long res=1;
        dp[0]=1;
        for(int i=1;i<=k+1;i++)
        {
            dp[i]=res;
            if(i<=n)
                res=(res+dp[i])%mod;
            else
                res=(res+dp[i]-dp[i-n]+mod)%mod;
            if(i>=m)
                res=(res-dp[i-m]+mod)%mod;
        }
        for(int i=0;i<10;i++)
        {
            printf("%lld ",dp[i]);
        }
        printf("\n");
        printf("%lld\n",dp[k+1]);
    }
    return 0;
}
