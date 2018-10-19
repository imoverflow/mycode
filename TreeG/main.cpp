#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 1000000000
using namespace std;
int cost[2000][2000];
int mincost[2000];
bool used[2000];
int V;
int prim()
{
    for(int i=0;i<=V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[1]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=V;u++)
        {
            if(!used[u] && (v==-1||mincost[u]<mincost[v]))
                v=u;
        }
        if(v==-1)
            break;
        used[v]=true;
        res+=mincost[v];
        for(int u=1;u<=V;u++)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
int main()
{
    int p,r;
    while(scanf("%d",&p)!=EOF&&p!=0)
    {
        scanf("%d",&r);
        for(int i=0;i<=p;i++)
        {
            for(int j=0;j<=p;j++)
            {
                cost[i][j]=INF;
            }
        }
        int a,b,c;
        for(int i=0;i<r;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(cost[a][b]>c)
            {
                cost[a][b]=c;
                cost[b][a]=c;
            }
        }
        V=p;
        int res=prim();
        printf("%d\n",res);
    }

    return 0;
}
