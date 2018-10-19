#include <iostream>
#include <bits/stdc++.h>
#define Max_V 40000
#define Max_q 200
#define Max_Log_V 4
using namespace std;

struct edge{
    int to,cost;
};
vector<edge>G[Max_V];
int dis[Max_V];
int root;
int parent[Max_Log_V][Max_V];
int depth[Max_V];
void add_edge(int a,int b,int c)
{
    G[a].push_back((edge){b,c});
    G[b].push_back((edge){a,c});
}
void dfs(int v,int p,int d)
{
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i].to!=p)
        {
            dis[G[v][i].to]=dis[v]+G[v][i].cost;
            dfs(G[v][i].to,v,d+1);
        }
    }
}
void init(int V)
{
    memset(dis,0,sizeof dis);
    dfs(root,-1,0);
    for(int k=0;k+1<Max_Log_V;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<Max_Log_V;k++)
    {
        if((depth[v]-depth[u])>>k &1){
            v=parent[k][v];
        }
    }
    if(u==v) return u;
    for(int k=Max_Log_V-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        root=1;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
            add_edge(b,a,c);
        }
        init(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int p=lca(a,b);
            printf("%d\n",dis[a]+dis[b]-dis[p]*2);
        }
    }
    return 0;
}
