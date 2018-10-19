#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,s;
int match[2000],w[2000][2000];
bool vis[2000];
bool hungary(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&w[x][i])
        {
            vis[i]=true;
            if(match[i]==-1||hungary(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&n);
        if(s<n)
            swap(s,n);
        if(n>1000)
        {
            printf("Case #%d: No\n",cas++);
            continue;
        }
        memset(w,0,sizeof w);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((s+i)%j==0)
                {
                    w[i][j]=1;
                }
            }
        }
        memset(match,-1,sizeof match);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            if(hungary(i)) res++;
        }
        if(res==n)
        {
            printf("Case #%d: Yes\n",cas++);
        }else{
            printf("Case #%d: No\n",cas++);
        }
    }
    return 0;
}
