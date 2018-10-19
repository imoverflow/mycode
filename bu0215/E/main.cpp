#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int s[20005];
int sum1[20005];
int sum2[20005];
int dp[2005][2005][2];
int main()
{
    int n;
    cin>>n;
    memset(sum1,0,sizeof sum1);
    memset(sum2,0,sizeof sum2);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sum1[i]+=sum1[i-1]+(s[i]==1);
    }
    for(int i=n;i>=1;i--)
    {
        sum2[i]+=sum2[i+1]+(s[i]==2);
    }
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[i][j][1]=dp[i][j-1][1]+(s[j]==2);
            dp[i][j][0]=max(dp[i][j-1][1],dp[i][j-1][0])+(s[j]==1);
            ans=max(ans,dp[i][j][0]+sum1[i-1]+sum2[j+1]);
            ans=max(ans,dp[i][j][1]+sum1[i-1]+sum2[j+1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
