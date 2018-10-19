#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,k,s,a[105],b[105],dp[105][105];
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j]=m;
        //dp[0][0]=0;
        for(int l=0;l<k;l++)
        {
            for(int i=a[l];i<=n;i++)
            {
                for(int j=s;j>=1;j--)
                {
                    if(dp[i-a[l]][j]-b[l]>=0)
                        dp[i][j]=min(dp[i-a[l]][j]-b[l],dp[i][j-1]);
                }
            }
        }
        if(dp[n][s]>=0)
            printf("%d\n",dp[n][s]);
        else
            printf("-1\n");
    }
    return 0;
}
