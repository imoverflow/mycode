#include<bits/stdc++.h>
#define M 300005
using namespace std;
struct E
{
    int u,v,w;
    E(int w,int u,int v):w(w),u(u),v(v) {}
    bool operator<(const E& rhp)const
    {
        return w>rhp.w;
    }
};
vector<E>e;
vector<int>g[M];
int fa[M];
int pre[M][30];
char s[10];

int findd(int u)
{
    return fa[u]==u?u:fa[u]=findd(fa[u]);
}

void dfs(int u,int fa)
{
    pre[u][0]=fa;
    for(int i=1; i<=19; i++)
        pre[u][i]=pre[pre[u][i-1]][i-1];
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

int lca(int u,int v)
{
    if(d[u]<d[v])
        swap(u,v);
    int dep=d[u]-d[v];
    for(int i=19; i>=0; i--)
    {
        if(dep&(1<<i))
        {
            dep^=(1<<i);
            u=pre[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=19; i>=0; i--)
    {
        if(pre[u][i]!=pre[v][i])
        {
            u=pre[u][i];
            v=pre[v][i];
        }
    }
    return pre[u][0];
}

void Kruskal()
{
    sort(e.begin(),e.end());
    for(i=0; i<e.size(); i++)
    {
        u=e[i].u;
        v=e[i].v;
        x=findd(u);
        y=findd(v);
        if(x!=y)
        {
            fa[x]=y;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(i=1; i<=(n+1)*m; i++)
        fa[i]=i;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            char s[10];
            scanf("%s%d%s%d",s,&a,s,&b);
            if(i<n)
            {
                e.push_back(E(a,i*m+j,(i+1)*m+j));
            }
            if(j<m)
            {
                e.push_back(E(b,i*m+j,i*m+j+1));
            }
        }
    }
    Kruskal();
    dfs(m+1,0);
    scanf("%d",&q);
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int u=x1*m+y1;
        int v=x2*m+y2;
        int l=lca(u,v);
        printf("%d\n",d[u]+d[v]-2*d[l]);
    }
}
