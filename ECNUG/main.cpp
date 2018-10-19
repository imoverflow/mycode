#include <iostream>
#include <stdio.h>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
#define INF 100000000
using namespace std;

long long n,m,M;
bool used[100050];
struct node{
    long long to,cost,sp;
};

bool cmp(const struct node &a,const struct node &b)
{
    if(a.sp<b.sp)
        return a.cost<b.cost;
    else
        return a.sp<b.sp;
}
vector<node>g[100050];
long long res1=0;
long long res2=0;
int prim()
{
    for(int i=1;i<=n;i++)
    {
        used[i]=false;
    }
    used[1]=true;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
        {
            if(!used[u]&&v==-1)
                v=u;
            else
            {
                if(v==-1)
                    continue;
                if(!used[u]&&g[u][0].to!=0&&!used[g[u][0].to]&&g[u][0].cost<g[v][0].cost&&g[u][0].sp<=g[v][0].sp)
                {
                    v=g[u][0].to;
                }else if(!used[u]&&g[u][0].to!=0&&!used[g[u][0].to]&&g[u][0].sp==0&&g[v][0].sp==1)
                    v=g[u][0].to;
            }
        }
        if(v==-1) break;
        used[v]=true;
//        for(int i=0;i<g[v].size();i++)
//        {
//            if(g[v][i].cost<p.second)
//            {
//                p.second=g[v][i].cost;
//                p.first=g[v][i].to;
//            }
//        }
        if(g[v][0].sp!=1)
            res1+=g[v][0].cost;
        else
            res2+=g[v][0].cost;
//        for(int u=1;u<=n;u++)
//        {
//            int j,flag1=0;
//            for(j=0;j<g[v].size();j++)
//            {
//                if(g[v][j].to==u)
//                {
//                    flag1=1;
//                    break;
//                }
//            }
//            if(flag1)
//                mincost[u]=min(mincost[u],g[v][j].cost);
//            else
//                mincost[u]=mincost[u];
//        }
    }
}
int main()
{

    scanf("%lld%lld%lld",&n,&m,&M);
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        node no;
        no.to=b;
        no.cost=c;
        no.sp=d;
        g[a].push_back(no);
        no.to=a;
        no.cost=c;
        no.sp=d;
        g[b].push_back(no);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end(),cmp);
    }
    prim();
    printf("%.10f\n",(double)(M-res1)/res2);
    return 0;
}
