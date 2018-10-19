#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 1000000000
using namespace std;
int d[1005];
int n,m;
int cost[1005][1005];
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
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }
}
int main()
{
    int a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cost[i][j]=INF;
            }
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(cost[a][b] == 0) cost[a][b] = cost[b][a] = c;
            else if(c < cost[a][b]) cost[a][b] = cost[b][a] = c;
        }
        int s,t;
        scanf("%d%d",&s,&t);
        dis(s);
        printf("%d\n",d[t]==INF?-1:d[t]);
    }
    return 0;
}
