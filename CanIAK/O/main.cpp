#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[505][505];
bool vis[505];
int match[505];
int k,m,n;
bool hungary(int u)
{
//    vis[u]=true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&s[u][i])
        {
            vis[i]=true;
            if(match[i]==-1||hungary(match[i]))
            {
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d",&k)&&k)
    {
        memset(s,0,sizeof s);
        memset(match,-1,sizeof match);
        scanf("%d%d",&m,&n);
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            s[a][b]=1;
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            memset(vis,0,sizeof vis);
            if(hungary(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
