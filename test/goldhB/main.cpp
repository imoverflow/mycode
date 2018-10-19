#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char s[55][55];
int cost[2600][2600];
int d[5000];
bool used[5000];
int n;
void dijk(int x)
{
    fill(d,d+n*n,INF);
    fill(used,used+n*n,false);
    d[x]=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<n*n;u++)
        {
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        }

        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<n*n;u++)
        {
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<=n*n;i++)
            for(int j=0;j<=n*n;j++)
                cost[i][j]=INF;
        for(int i=0;i<n*n;i++)
        {
            if(i%n+1<n)
            {
                if(s[i/n][i%n]=='*')
                {
                    if(s[i/n][i%n+1]=='*')
                        cost[i][i+1]=0;
                    else
                        cost[i][i+1]=1;
                }else{
                        cost[i][i+1]=1;
                }
            }
            if(i%n-1>=0)
            {
                if(s[i/n][i%n]=='*')
                {
                    if(s[i/n][i%n-1]=='*')
                        cost[i][i-1]=0;
                    else
                        cost[i][i-1]=1;
                }else{
                        cost[i][i-1]=1;
                }
            }
            if(i-n>=0)
            {
                if(s[i/n][i%n]=='*')
                {
                    if(s[i/n-1][i%n]=='*')
                        cost[i][i-n]=0;
                    else
                        cost[i][i-n]=1;
                }else{
                        cost[i][i-n]=1;
                }
            }
            if(i+n<n*n)
            {
                if(s[i/n][i%n]=='*')
                {
                    if(s[i/n+1][i%n]=='*')
                        cost[i][i+n]=0;
                    else
                        cost[i][i+n]=1;
                }else{
                        cost[i][i+n]=1;
                }
            }
        }
        dijk(0);
        printf("%d\n",d[n*n-1]);
    }
    return 0;
}
