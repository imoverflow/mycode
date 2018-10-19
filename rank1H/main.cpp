#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    //freopen("a.txt","r",stdin);
    int t,s[100][3],dp[100][3];
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=s[0][0];
        dp[0][1]=s[0][1];
        dp[0][2]=s[0][2];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                    dp[i][j]=min(dp[i-1][1]+s[i][j],dp[i-1][2]+s[i][j]);
                if(j==1)
                    dp[i][j]=min(dp[i-1][0]+s[i][j],dp[i-1][2]+s[i][j]);
                if(j==2)
                    dp[i][j]=min(dp[i-1][0]+s[i][j],dp[i-1][1]+s[i][j]);
            }
        }
        printf("Case %d: %d\n",k,min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
    }
    return 0;
}
