#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <math.h>
#define INF 0x3f3f3f3f
using namespace std;

int cost[500][500];
int mincost[500];
bool used[500];
int n,s,e,ans=0;
int prim(){
    for(int i=0;i<=n;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        mincost[i]=cost[s][i];
    }
    mincost[s]=0;
    used[s]=true;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=n;u++)
        {
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                v=u;
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=1;u<=n;u++)
        {
            if(!used[u] && mincost[u]>mincost[v]+cost[v][u]){
                mincost[u]=mincost[v]+cost[v][u];
            }
        }
    }
    return res;
}
int main()
{
    while(scanf("%d%d%d",&n,&s,&e)!=EOF)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cost[i][j]=INF;
            }
        }
        getchar();
        for(int i=1;i<=n;i++)
        {
            int a,b;
            char c;
            while(scanf("%*c%d %d%*c",&a,&b))
            {
                cost[i][a]=b;
                c=getchar();
                if(c=='\n')
                    break;
            }
        }
        prim();
        printf("%d\n",mincost[e]);
    }
    return 0;
}
