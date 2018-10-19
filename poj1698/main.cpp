#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct Node
{
    int to,cap,rev;
};
vector<Node> g[2500];
bool used[2500];

void add_edge(int from,int to ,int cap)
{
    Node n;
    n.to=to;
    n.cap=cap;
    n.rev=g[to].size();
    g[from].push_back(n);
    n.to=from;
    n.cap=0;
    n.rev=g[from].size()-1;
    g[to].push_back(n);
}

int dfs(int v,int t,int f)
{
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<g[v].size();i++)
    {
        Node &e=g[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
int main()
{
    int week[10];
    int t,film,di,wi,sumdate;
    cin>>t;
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(used,0,sizeof(used));
        sumdate=0;
        scanf("%d",&film);
        for(int i=1;i<=film;i++)
        {
            for(int j=0;j<7;j++)
                scanf("%d",&week[j]);
            scanf("%d%d",&di,&wi);
            add_edge(0,i,di);
            sumdate+=di;
            for(int j=0;j<7;j++)
            {
                if(week[j]==1)
                {
                    for(int k=0;k<wi;k++)
                        add_edge(i,film+1+k*7+j,1);      //  不要在后面加上add_edge(film+1+k*7+j,372,1); 这会导致重边的出现
                }
            }
        }
        for(int j=film+1;j<372;j++)
        {
            add_edge(j,372,1);
        }
        if(sumdate==max_flow(0,372))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
