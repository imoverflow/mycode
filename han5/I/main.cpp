#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int cost1[1005][1005];
int cost2[1005][1005];
int dis[1005];
int n,m,x;
int d[1005];
int used[1005];
void dijk1(int s)
{
    fill(d,d+n+1,INF);
    fill(used,used+n+1,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
        {
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=1;u<=n;u++)
        {
            d[u]=min(d[u],d[v]+cost1[v][u]);
        }
    }
}
void dijk2(int s)
{
    fill(d,d+n+1,INF);
    fill(used,used+n+1,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
        {
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=1;u<=n;u++)
        {
            d[u]=min(d[u],d[v]+cost2[v][u]);
        }
    }
}
int main()
{
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            cost1[i][j]=INF;
            cost2[i][j]=INF;
        }
    }
    memset(dis,0,sizeof dis);
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cost1[a][b]=c;
        cost2[b][a]=c;
    }
    dijk2(x);
    for(int i=1;i<=n;i++)
    {
        dis[i]+=d[i];
    }
    dijk1(x);
    for(int i=1;i<=n;i++)
    {
        dis[i]+=d[i];
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,dis[i]);
    }
    printf("%d\n",res);
    return 0;
}
