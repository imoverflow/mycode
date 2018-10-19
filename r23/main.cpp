#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int n,p,m,s[1005],dp[1005];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        scanf("%d",&m);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        sort(s,s+n);
        int ma=s[n-1];
        for(int i=0;i<=m;i++)
            dp[i]=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=m-5;j>=s[i];j--)
            {
                dp[j]=max(dp[j-s[i]]+s[i],dp[j]);
            }
        }
        printf("%d\n",m-dp[m-5]-ma);
    }
    return 0;
}
