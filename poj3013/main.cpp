#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
#define INF 100000000000000000
using namespace std;
int V,E;
typedef pair<long long ,long long> P;
long long we[500005];
long long d[500005];
struct edge{
    long long cost,to;
};
edge ED;
vector<edge> g[500005];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V+1,INF);
    d[s]=0;
    que.push(P(0,s));

    while(que.size())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<g[v].size();i++)
        {
            ED=g[v][i];
            if(d[ED.to]>d[v]+ED.cost){
                d[ED.to]=d[v]+ED.cost;
                que.push(P(d[ED.to],ED.to));
            }
        }
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out1.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(we,0,sizeof(we));
        memset(g,0,sizeof(g));
        scanf("%d%d",&V,&E);
        for(int i=1;i<=V;i++)
            scanf("%lld",&we[i]);
        for(int i=0;i<E;i++)
        {
            long long a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            ED.to=b;
            ED.cost=c;
            g[a].push_back(ED);
            ED.to=a;
            ED.cost=c;
            g[b].push_back(ED);
        }
        dijkstra(1);
        long long sum=0;
        int flag=1;
        for(int i=2;i<=V;i++)
        {
            if(d[i]==INF)
            {
                flag=0;
                break;
            }
            sum+=d[i]*we[i];
        }
        if(flag)
            printf("%lld\n",sum);
        else
            printf("No Answer\n");
    }
    return 0;
}
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//const int maxn=50000+5;
//const long long INF=0x3f3f3f3f3f;
//int weight[maxn];
//int cnt;
//int head[maxn];
//long long dis[maxn];
//bool vis[maxn];
//int n,m;
//struct Edge
//{
//    int to,w,next;
//} edge[maxn<<1];
//
//struct Node
//{
//    int u,dis;
//    bool operator <(const Node &a) const
//    {
//        return dis>a.dis;
//    }
//};
//void Init()
//{
//    cnt=0;
//    memset(head,-1,sizeof(head));
//    memset(vis,false,sizeof(vis));
//    for(int i=0; i<=n; i++)
//        dis[i]=INF;
//}
//void addEdge(int u,int v,int w)
//{
//    edge[cnt].to=v;
//    edge[cnt].w=w;
//    edge[cnt].next=head[u];
//    head[u]=cnt++;
//}
//void Dijkstra(int s)
//{
//    Node now,next;
//    priority_queue<Node>q;
//    now.dis=0;
//    now.u=s;
//    dis[s]=0;
//    q.push(now);
//    while(!q.empty())
//    {
//        now=q.top();
//        q.pop();
//        if(vis[now.u])
//            continue;
//        int u=now.u;
//        vis[u]=true;
//        for(int i=head[u]; i!=-1; i=edge[i].next)
//        {
//            int to=edge[i].to;
//            if(!vis[to]&&dis[u]+edge[i].w<dis[to])
//            {
//                dis[to]=dis[u]+edge[i].w;
//                next.dis=dis[to];
//                next.u=to;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    freopen("in.txt","r",stdin);
//    freopen("out2.txt","w",stdout);
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        cin>>n>>m;
//        Init();
//        for(int i=1; i<=n; i++)
//            scanf("%d",&weight[i]);
//        int u,v,w;
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d%d",&u,&v,&w);
//            addEdge(u,v,w);
//            addEdge(v,u,w);
//        }
//        Dijkstra(1);
//        long long sum=0;
//        bool flag=true;
//        for(int i=2; i<=n; i++)
//        {
//            if(dis[i]==INF)
//            {
//                flag=false;
//                break;
//            }
//            sum+=dis[i]*weight[i];
//        }
//        if(flag)
//            cout<<sum<<endl;
//        else
//            cout<<"No Answer"<<endl;
//    }
//    return 0;
//}
