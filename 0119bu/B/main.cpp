#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long INF=9223372036854775807;
long long s[31];
long long dp[31];
long long a[31];
int main()
{
    int n,L;
    memset(a,0,sizeof a);
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&dp[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        dp[i+1]=min(dp[i+1],2*dp[i]);
    }
    long long ans=INF;
    long long sum=0;
    for(int i=n-1;i>=0;i--)
    {
        long long need=L/(1<<i);
        sum+=need*dp[i];
        L-= need<<i;
        ans=min(ans,sum+(L>0)*dp[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
