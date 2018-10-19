#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int s[15][15];
int dp[1<<16][15];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        memset(dp,0,sizeof dp);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        for(int k=0;k<=n;k++)
        {
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
                }
            }
        }
        int tot=1<<n;
        for(int S=0;S<tot;S++)
        {
            for(int i=1;i<=n;i++)
            {
                if(S&(1<<(i-1)))
                {
                    if(S==(1<<(i-1)))
                    {
                        dp[S][i]=s[0][i];
                    }else{
                        dp[S][i]=(1<<30);
                        for(int j=1;j<=n;j++)
                        {
                            if(S&(1<<(j-1))&&j!=i)
                                dp[S][i]=min(dp[S][i],dp[S^(1<<(i-1))][j]+s[j][i]);
                        }
                    }
                }
            }
        }
        int ans=(1<<31)-1;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,dp[(1<<n)-1][i]+s[i][0]);
        }
        printf("%d\n",ans);
    }

    return 0;
}
