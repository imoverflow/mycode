#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int d[200005];
int pre[200005];

void dfs(int now,int fa,int dis)
{
    pre[now]=fa;
    d[now]=dis;
    for(int i=0;i<g[now].size();i++)
    {
        if(g[now][i]!=fa)
            dfs(g[now][i],now,dis+1);
    }
}
tuple<int,int,int>ans[200005];
bool vis[200005];
long long sum;
int cnt;
int leaf=1;
int root=1;
void Find(int now,int ld,int rd,bool isfirst)
{
    for(int i=0;i<g[now].size();i++)
    {
        if(!vis[g[now][i]]&&g[now][i]!=pre[now])
            Find(g[now][i],ld+1,rd+1,false);
    }
    if(!isfirst)
    {
        if(ld>rd)
        {
            ans[cnt++]=make_tuple(root,now,now);
            sum+=ld;
        }else{
            ans[cnt++]=make_tuple(leaf,now,now);
            sum+=rd;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(root,0,0);
    for(int i=1;i<=n;i++)
    {
        if(d[root]<d[i])
            root=i;
    }

    dfs(root,0,0);
    for(int i=1;i<=n;i++)
    {
        if(d[leaf]<d[i])
            leaf=i;
    }
    cnt=0;
    sum=0;
    int p=leaf;
    while(1)
    {
        vis[p]=1;
        Find(p,d[p],d[leaf]-d[p],1);
        if(p==root)
            break;
        p=pre[p];
    }
    p=leaf;
    while(p!=root)
    {
        ans[cnt++]=make_tuple(root,p,p);
        sum+=d[p];
        p=pre[p];
    }
    printf("%I64d\n",sum);
    for(int i=0;i<cnt;i++)
    {
        int a,b,c;
        tie(a,b,c)=ans[i];
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
