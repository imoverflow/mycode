#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int n,q;
int dp[(1<<10)+10];
int ans[(1<<10)+10];
int cnt[(1<<10)+10];
char s[10];
void add(int u,int v)
{
    int t=(1<<u)+(1<<v);
    for(int i=(1<<n)-1; i>=0; i--)
    {
        if((i&t)==0)
            dp[i^t]=dp[i]+dp[i^t]>mod?(dp[i]+dp[i^t]-mod):dp[i]+dp[i^t];
    }
}

void del(int u,int v)
{
    int t=(1<<u)+(1<<v);
    for(int i=0,j=1<<n; i<j; i++)
    {
        if((i&t)==0)
        {
            dp[i^t]=dp[i^t]-dp[i]<0?(dp[i^t]-dp[i]+mod):dp[i^t]-dp[i];
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0,j=(1<<n); i<j; i++)
        {
            dp[i]=0;
            cnt[i]=__builtin_popcount(i);
        }
        dp[0]=1;
        for(int i=0; i<q; i++)
        {
            int u,v;
            scanf("%s%d%d",s,&u,&v);
            u--,v--;
            if(s[0]=='+')
                add(u,v);
            else
                del(u,v);
            memset(ans,0,sizeof(int)*(n+3));
            for(int i=1,j=1<<n;i<j;i++)
                ans[cnt[i]]=ans[cnt[i]]+dp[i]>mod?ans[cnt[i]]+dp[i]-mod:ans[cnt[i]]+dp[i];
            for(int i=2;i<=n;i+=2)
                printf("%d%c",ans[i],i<n?' ':'\n');
        }

    }
    return 0;
}
