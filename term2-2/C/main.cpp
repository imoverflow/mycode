#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int to,cap,cost,rev;
};
int V,m,x;
vector<edge>g[10004];
int dist[10004];
int prevv[10004],preve[10004];
void add_edge(int from,int to ,int cap,int cost)
{
    g[from].push_back((edge){to,cap,cost,g[to].size()});
    g[to].push_back((edge){from,0,-cost,g[from].size()-1});
}
int mincost(int s,int t,int f)
{
    int res=0;
    while(f>0)
    {
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update=true;
        while(update)
        {
            update=false;
            for(int v=1;v<=V;v++)
            {
                if(dist[v]==INF) continue;
                for(int i=0;i<g[v].size();i++)
                {
                    edge &e=g[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
                    {
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t]==INF){
            return -1;
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,g[prevv[v]][preve[v]].cost);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=g[prevv[v]][preve[v]];
            e.cap-=d;
            g[v][e.rev].cap+=d;
        }
    }
    return res;
}
//int a[100004][2];
//int b[100004][2];
int main()
{
    while(~scanf("%d%d%d",&V,&m,&x))
    {
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,1,c);
        }

        printf("%d\n",mincost(1,V,1));
    }
    return 0;
}
