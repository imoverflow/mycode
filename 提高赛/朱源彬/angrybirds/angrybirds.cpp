#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int>g[300005];
int ob[300005];
int ans[300005;

void bfs(int s,int e,int t)
{
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int k=q.front();
        if(k==e)
        {
            if(ob[e]==t)
                ans[e]++;
            break;
        }
        for(int i=0;i<g[k].size();i++)
        {
            bfs(g[k][i],e,t+1);
        }
    }
}
int main()
{
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    memset(g,0,sizeof(g));
    memset(ob,0,sizeof(ob));
    memset(ans,0,sizeof(ans));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ob[i]);
    }
    for(int i=0;i<m;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        bfs(s,e,0);
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            printf("%d",ans[i]);
        else
            printf(" %d",ans[i]);
    }
    puts("");
    return 0;
}
