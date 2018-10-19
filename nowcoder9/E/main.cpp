#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double p[1005];
double dp[1005][1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        p[i]=a/100.0;
    }

    dp[1][1]=p[1];
    dp[1][0]=(1-p[1]);
    double ans=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j>=1)
                dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
            else
                dp[i][j]=dp[i-1][j]*(1-p[i]);
            ans+=pow(j,m)*dp[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
