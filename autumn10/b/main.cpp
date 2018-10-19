#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <valarray>
#include <vector>
#include <cstring>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    long long x,y,r,c;
}s[1005];
bool vis[1005];
bool con[1005][1005];
int deg[1005];
long long dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int n;
void dfs(long long x,long long &cost)
{
    vis[x]=true;
    cost=min(cost,s[x].c);
    for(long long i=0;i<n;i++)
    {
        if(!vis[i]&&con[x][i])
        {
            if(cost>s[i].c)
            {
                cost=s[i].c;
                dfs(i,cost);
            }
            else
            {
                dfs(i,cost);
            }
        }
    }
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof vis);
        memset(con,0,sizeof con);
        memset(deg,0,sizeof deg);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld%lld%lld",&s[i].x,&s[i].y,&s[i].r,&s[i].c);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                if(dis(s[i],s[j])<=s[i].r*s[i].r)
                {
                    con[i][j]=true;
                    deg[j]++;
                }
            }
        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                printf("%d ",con[i][j]);
//            }
//            printf("\n");
//        }
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            if(!vis[i]&&deg[i]==0)
            {
                long long x=INF;
                dfs(i,x);
                ans+=s[i].c;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                long long x=INF;
                dfs(i,x);
                ans+=x;
            }
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
