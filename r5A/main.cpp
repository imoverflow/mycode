#include <iostream>
#include <stdio.h>
#define INF 1000000000
using namespace std;
int n,m;
int cost[1005][1005];
int d[1005];
bool used[1005];
void dis(int s)
{
    fill(d,d+n,INF);
    fill(used,used+n,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<n;u++)
        {
            if(!used[u] && (v==-1||d[u]<d[v]))
                v=u;
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<n;u++)
        {
            if(u==s) continue;
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cost[i][j]=INF;
        }
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            cost[a-1][b-1]=c;
            cost[b-1][a-1]=c;
        }
        dis(0);
        printf("%d\n",d[n-1]);
    }
    return 0;
}
