#include <iostream>
#include <bits/stdc++.h>
#define Max_V 100
#define Max_q 100
#define Max_Log_V 10
using namespace std;

/**********************************************/
/**                传统lca                  **/
/*********************************************/
//vector<int>G[Max_V];
//int root;
//int parent[Max_Log_V][Max_V];
//int depth[Max_V];
//void dfs(int v,int p,int d)
//{
//    parent[0][v]=p;
//    depth[v]=d;
//    for(int i=0;i<G[v].size();i++)
//    {
//        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
//    }
//}
//void init(int V)
//{
//    dfs(root,-1,0);
//    for(int k=0;k+1<Max_Log_V;k++)
//    {
//        for(int v=0;v<V;v++)
//        {
//            if(parent[k][v]<0) parent[k+1][v]=-1;
//            else parent[k+1][v]=parent[k][parent[k][v]];
//        }
//    }
//}
//int lca(int u,int v)
//{
//    if(depth[u]>depth[v]) swap(u,v);
//    for(int k=0;k<Max_Log_V;k++)
//    {
//        if((depth[v]-depth[u])>>k &1){
//            v=parent[k][v];
//        }
//    }
//    if(u==v) return u;
//    for(int k=Max_Log_V-1;k>=0;k--)
//    {
//        if(parent[k][u]!=parent[k][v])
//        {
//            u=parent[k][u];
//            v=parent[k][v];
//        }
//    }
//    return parent[0][u];
//}
/*********************************************/
/**                  END                    **/
/*********************************************/

/**********************************************/
/**        利用lca求树节点之间的距离       **/
/*********************************************/
//struct edge{
//    int id,to,cost;
//};
//
//int n,q,s;
//
//int a[Max_V-1],b[Max_V-1],w[Max_V-1];
//int type[Max_q];   /**处理类型 0：输出从当前位置移动到节点x所需要的时间**/
//                   /**处理类型 1：将通过道路x所需的时间改为t            **/
//int x[Max_q],t[Max_q];
//vector<edge>G[Max_V];
//int root;
//int vs[Max_V*2-1];      /**DFS访问顺序**/
//int depth[Max_V*2-1];   /**  节点深度 **/
//int id[Max_V];          /**各个节点在vs中首次出现的下标**/
//int es[(Max_V-1)*2];
//
//void dfs(int v,int p,int d,int &k)
//{
//    id[v]=k;
//    vs[k]=v;
//    depth[k++]=d;
//    for(int i=0;i<G[v].size();i++)
//    {
//        edge &e=G[v][i];
//        if(!e.to!=p)
//        {
//            add(k,e.cost);
//            es[e.id*2]=k;
//            dfs(e.to,v,d+1,k);
//            vs[k]=v;
//            depth[k++]=d;
//            add(k,-e.cost);
//            es[e.id*2+1]=k;
//        }
//    }
//}
//int stack_v[Max_V+10];
//int stack_i[Max_V+10];
//void init(int V)
//{
//    bit_n=(V-1)*2;
//    int k=0;
//    dfs(root,-1,0,k);
//    rmq_init(depth,V*2-1);
//}
//int lca(int u,int v)
//{
//    return vs[quary(min(id[u],id[v])),max(id[u],id[v])+1];
//}
//void solve(){
//    root=n/2;
//    for(int i=0;i<n-1;i++)
//    {
//        G[a[i]-1].push_back((edge){i,b[i]-1,w[i]});
//        G[b[i]-1].push_back((edge){i,a[i]-1,w[i]});
//    }
//    init(n);
//    /**查询**/
//    int v=s-1;
//    for(int i=0;i<q;i++)
//    {
//        if(type[i]==0)
//        {
//            int u=x[i]-1;
//            int p=lca(v,u);
//            printf("%d\n",sum(id[v])+sum(id[u])-sum(id[p])*2);
//            v=u;
//        }else{
//            int k=x[i]-1;
//            add(es[k*2],t[i]-w[k]);
//            add(es[k*2-1],w[k]-t[i]);
//            w[k]=t[i];
//        }
//    }
//}
/**********************************************/
/**            不知道这是什么鬼啊          **/
/*********************************************/

/**********************************************/
/**               离线Tarjan算法            **/
/*********************************************/
const int MAXN = 1000;
const int MAXQ = 50000;

int F[MAXN];           /**并查集**/
int find(int x)
{
    if(F[x]==-1) return x;
    return F[x]=find(F[x]);
}
void unio(int u,int v)
{
    int t1=find(u);
    int t2=find(v);
    if(t1!=t2)
        F[t1]=t2;
}
bool vis[MAXN];
int ancestor[MAXN];
struct Edge{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;                 //前向星？？
}
struct Query
{
    int q,next;
    int index;                    //查询编号
}query[MAXQ*2];
int answer[MAXQ];
int h[MAXQ];
int tt;
int Q;

void add_query(int u,int v,int index)
{
    query[tt].q = v;
    query[tt].next = h[u];
    query[tt].index = index;
    h[u] = tt++;
    query[tt].q = u;
    query[tt].next = h[v];
    query[tt].index = index;
    h[v] = tt++;
}

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    tt = 0;
    memset(h,-1,sizeof(h));
    memset(vis,false,sizeof(vis));
    memset(F,-1,sizeof(F));
    memset(ancestor,0,sizeof(ancestor));
}

void LCA(int u)
{
    ancestor[u] = u;
    vis[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v])continue;
        LCA(v);
        unio(u,v);
        ancestor[find(u)] = u;
    }
    for(int i = h[u];i != -1;i = query[i].next)
    {
        int v = query[i].q;
        if(vis[v])
        {
            answer[query[i].index] = ancestor[find(v)];
        }
    }
}

bool flag[MAXN]; int Count_num[MAXN];

int main()
{
    int n;
    int u,v,k;
    while(scanf("%d",&n) == 1)
    {
        init();
        memset(flag,false,sizeof(flag));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d %d",&u,&k);
            while(k--)
            {
                scanf("%d",&v);
                flag[v] = true;
                add_edge(u,v);
                add_edge(v,u);
            }
        }
        scanf("%d",&Q);
        for(int i = 0;i < Q;i++)
        {
            char ch;
            cin>>ch;
            scanf("%d %d)",&u,&v);
            add_query(u,v,i);
        }
        int root;
        for(int i = 1;i <= n;i++)
        {
            if(!flag[i])
            {
                root = i;
                break;
            }
        }
        LCA(root);
        memset(Count_num,0,sizeof(Count_num));
        for(int i = 0;i < Q;i++)
            Count_num[answer[i]]++;
        for(int i = 1;i <= n;i++)
            if(Count_num[i] > 0)
                printf("%d:%d\n",i,Count_num[i]);
    }
    return 0;
}
/*********************************************/
/**                  END                    **/
/*********************************************/

/**********************************************/
/**               离线Tarjan算法            **/
/*********************************************/
#include <cstdio>
#include <cstring>
int const MAX = 40005;

struct Edge
{
    int id, val; //当前边序号，边权
    int next;  //下一条
}e[2 * MAX];

int n, m, cnt;
//x, y表示询问的起点和终点，z是x和y的LCA
int x[MAX], y[MAX], z[MAX];
//fa存祖先，dist存到根的距离，pre存父亲
int fa[MAX], dist[MAX], pre[MAX];
bool vis[MAX];

void AddEdge(int u, int v, int w)
{
    e[cnt].id = u;
    e[cnt].val = w;
    e[cnt].next = pre[v];
    pre[v] = cnt++;

    e[cnt].id = v;
    e[cnt].val = w;
    e[cnt].next = pre[u];
    pre[u] = cnt++;
}

int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void tarjan(int k)
{
    vis[k] = true;
    fa[k] = k;
    for(int i = 1; i <= m; i++)
    {
        if(x[i] == k && vis[y[i]])
            z[i] = Find(y[i]);
        if(y[i] == k && vis[x[i]])
            z[i] = Find(x[i]);
    }
    for(int i = pre[k]; i != -1; i = e[i].next)
    {
        if(!vis[e[i].id])
        {
            dist[e[i].id] = dist[k] + e[i].val;
            tarjan(e[i].id);
            fa[e[i].id] = k;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int u, v, w;
        scanf("%d %d", &n, &m);
        cnt = 0;
        memset(pre, -1, sizeof(pre));
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            AddEdge(u, v, w);
        }
        for(int i = 1; i <= n; i++)
            x[i] = y[i] = z[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            x[i] = u;
            y[i] = v;
        }
        memset(vis, false, sizeof(vis));
        dist[1] = 0;
        tarjan(1);
        for(int i = 1; i <= m; i++)
            printf("%d\n",dist[x[i]] + dist[y[i]] - 2 * dist[z[i]]);
    }
}

/*********************************************/
/**                  END                    **/
/*********************************************/
