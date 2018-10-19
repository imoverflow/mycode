#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct most{
    int hp,def;
}s1[100005];
struct att{
    int dam,cost;
}s2[1005];
long long dp[1005][11];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int maxatt=0,maxdef=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&s1[i].hp,&s1[i].def);
            maxdef=max(maxdef,s1[i].def);
        }
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=10;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=INF;
            }
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&s2[i].cost,&s2[i].dam);
            maxatt=max(maxatt,s2[i].dam);
        }
        if(maxatt<=maxdef)
        {
            printf("-1\n");
            continue;
        }
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<=10;j++)
            {
                if(s2[k].dam<=j) break;
                for(int i=1;i<=1000;i++)
                {
                    if(i-s2[k].dam+j>=0)
                        dp[i][j]=min(dp[i][j],dp[i-s2[k].dam+j][j]+s2[k].cost);
                    else
                        dp[i][j]=min(dp[i][j],(long long)s2[k].cost);
                }
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=dp[s1[i].hp][s1[i].def];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
