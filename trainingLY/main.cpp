#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 1<<15
using namespace std;
int v[10005];
int to[10005];
int dp[10005];
int main()
{
    int t,n;
    double p;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        memset(v,0,sizeof v);
        memset(to,0,sizeof(to));
        memset(dp,0,sizeof(dp));
        scanf("%lf%d",&p,&n);
        int P=(p+0.00005)*10000;
        double m;
        for(int i=0;i<n;i++)
        {
            scanf("%d%lf",&v[i],&m);
            int temp=(m+0.00005)*10000;
            to[i]=temp;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=P;j>=to[i];j--)
            {
                dp[j]=max(dp[j],dp[j-to[i]]+v[i]);
            }
        }
        printf("Case %d: %d\n",k,dp[P]);
    }
    return 0;
}
