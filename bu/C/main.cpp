#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int color[200005];
vector<int>g[200005];
long long ans;
long long dfs(int u,int v)
{
    long long add=0;
    long long pre=b[color[u]];
    a[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        if(g[u][i]==v) continue;
        dfs(g[u][i],u);
        a[u]+=a[g[u][i]];
        long long s=a[g[u][i]]-(b[color[u]]-pre);
        pre=b[color[u]];
        add+=s;
        ans-=s*(s-1)/2;
    }
    b[color[u]]+=add+1;
}
int main()
{
    long long n;
    int cases=1;
//    freopen("1003.in","r",stdin);
//    freopen("myout.out","w",stdout);
    while(~scanf("%lld",&n))
    {
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
        }
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(color,0,sizeof color);
        ans=n*(n-1)/2*n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&color[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            ans-=(n-b[i])*(n-b[i]-1)/2;
        }
        printf("Case #%d: %lld\n",cases++,ans);
    }
    return 0;
}
