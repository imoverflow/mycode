#include <iostream>
#include <stdio.h>
#define INF 1000000000
using namespace std;
int cost[105][105];
int mincost[105];
bool used[100000];
int V;

int prim(){
    for(int i=0;i<V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
        {
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                v=u;
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&cost[i][j]);
            }
        }
        V=n;
        int ans=prim();
        printf("%d\n",ans);
    }
    return 0;
}
