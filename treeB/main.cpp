#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[40005];
int root;
int parent[4000][40005];
int depth[40005];

void dfs(int v,int p,int d)
{
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
}

void init(int V)
{
    dfs(root,-1,0);
    for(int k=0;k+1<4005;k++)
    {
        for(int v=0;v<V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<4005;k++)
    {
        if((depth[v]-depth[u])>>k&1)
        {
            v=parent[k][v];
        }
    }
    if(u==v)
        return u;
    for(int k=4005;k>=0;k--)
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
    int t,n,m,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init(n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
//            G[a][b]=c;
//            G[b][a]=c;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",lca(a,b));
        }
    }
    return 0;
}
