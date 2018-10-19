#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int dp[25][10005];
int s[25][10005];
int vis[25][10005];
bool check(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int dfs(int x,int y)
{
    if(vis[x][y]) return dp[x][y];
    else{
        vis[x][y]=1;
        int t=-INF;
        if(check(x+1,y))
            t=max(t,dfs(x+1,y));
        if(check(x,y+1))
            t=max(t,dfs(x,y+1));
        for(int i=2;i*y<=m;i++){
            if(check(x,i*y))
                t=max(t,dfs(x,y*i));
        }
        if(t==-INF) t=0;
        return dp[x][y]=t+s[x][y];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof s);
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        dfs(1,1);
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
