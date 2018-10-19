#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
//http://acm.hdu.edu.cn/showproblem.php?pid=1532

struct Node
{
    int to,cap,rev;
};
vector<Node> g[2500];
bool used[2500];

void add_edge(int from,int to ,int cap)
{
//    Node n;
//    n.to=to;
//    n.cap=cap;
//    n.rev=g[to].size();
//    g[from].push_back(n);
//    n.to=from;
//    n.cap=0;
//    n.rev=g[from].size()-1;
//    g[to].push_back(n);
    v[from].push_back((Node){to,cap,v[to].size()});
    v[to].push_back((Node){from,0,v[from].size()-1});
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
                e.cap-=d;                  //Flow to zero
                g[e.to][e.rev].cap+=d;     //rev to zero
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
    int m,n;
    while(cin>>n>>m){
            memset(g,0,sizeof g);
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
        }
        printf("%d\n",max_flow(1,m));
    }
    return 0;
}
