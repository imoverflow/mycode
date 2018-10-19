#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long dp[1000006];
int main()
{
    int n,mod;
    while(~scanf("%d%d",&n,&mod))
    {
        dp[0]=1;
        long long sum=0;
        for(int i=1; i<=n; i++)
        {
            dp[i]=dp[i-2]*(i-1LL)%mod;
            sum=sum*(i-1)%mod;
            if(i>=3)
            {
                sum=sum+((i-1LL)*(i-2)/2%mod*dp[i-3]%mod);
                sum%=mod;
            }
            dp[i]=(dp[i]+sum)%mod;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
