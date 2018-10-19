#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int MAXN=20010;
const int MAXM=50010;

struct Edge{
    int to,next;
}edge[MAXM];

int head[MAXN],tot,low[MAXN],dfn[MAXN],Stack[MAXN],belong[MAXN],index,top,scc;  //强连通分量的个数
bool instack[MAXN];
int num[MAXN];

void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void Tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        }else if(instack[v]&&low[u]>low[v])
        {
            low[u]=dfn[v];
        }
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            instack[v]=false;
            belong[v]=scc;
            num[scc]++;
        }while(v!=u);
    }
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(num,0,sizeof(num));
    index=scc=top=0;
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i])
        {
            Tarjan(i);
        }
    }
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        init();
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        solve(n);
        if(scc==1)
        {
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
