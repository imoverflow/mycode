#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> P;
struct edge{
    int to,cost;
};
vector<edge>G[100005];
int d[100005];
int mincost[100005];
int prev[100005];
int n,m;
set<int>ss;
long long dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+n+1,INF);
    fill(prev,prev+n+1,-1);
    d[s]=0;
    P xx;
    xx.first=INF;
    xx.second=INF;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                xx.second=xx.first>d[v]+e.cost?xx.first:xx.second;
                xx.first=min(xx.first,d[v]+e.cost);
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
                prev[e.to]=v;
            }
        }
    }
    return xx;
}
bool cmp(const edge &a,const edge &b)
{
    return a.cost>b.cost;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
//        memset(vis,0,sizeof vis);
        memset(G,0,sizeof G);
        scanf("%d%d",&n,&m);
        fill(mincost,mincost+n+1,INF);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back((edge){b,c});
            G[b].push_back((edge){a,c});
            mincost[a]=min(mincost[a],c);
            mincost[b]=min(mincost[b],c);
        }
        for(int i=1;i<=n;i++)
        {
            sort(G[i].begin(),G[i].end(),cmp);
        }
        long long res=dijkstra(1);
        for(int i=5;i!=-1;i=prev[i])
        {
            printf("%d\n",i);
            ss.insert(i);
        }
//        set<int>::iterator it=ss.begin();
//        for(;it!=ss.end();it++)
//        {
//            printf("%d\n",(*it));
//        }

    }
    return 0;
}
/*
10
5 6
1 2 1
1 3 2
1 4 3
2 5 1
3 5 2
4 5 3
*/
