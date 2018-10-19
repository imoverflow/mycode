#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int>g[300005];
int ob[300005];
int ans[300005];
typedef pair<int ,int> P;
queue<P>q;
int vis[300005];
//void bfs(int s,int e)
//{
//    q.push(P(s,0));
//    vis[s]=1;
//    while(!q.empty())
//    {
//        P k=q.front();
//        q.pop();
//        if(ob[k.first]==k.second)
//            ans[k.first]++;
//        if(k.first==e)
//        {
//            break;
//        }
//        for(int i=0;i<g[k.first].size();i++)
//        {
//            if(vis[g[k.first][i]]==0)
//            {
//                vis[g[k.first][i]]=1;
//                q.push(P(g[k.first][i],k.second+1));
//            }
//        }
//    }
//}
bool dfs(int s,int e,int t)
{
    if(s==e){
        return true;
    }
    vis[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        if(!vis[g[s][i]]&&dfs(g[s][i],e,t+1))
        {
            if(ob[g[s][i]]==t+1)
                ans[g[s][i]]++;
            return true;
        }
    }
    return false;
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
        memset(vis,0,sizeof(vis));
        int s,e;
        scanf("%d%d",&s,&e);
//        bfs(s,e);
//        while(q.size())
//            q.pop();
        if(ob[s]==0)
            ans[s]++;
        dfs(s,e,0);
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
/*
6 3
2 3
1 2
1 4
4 5
4 6
0 2 5 1 2 3
1 5
1 3
2 6
*/
