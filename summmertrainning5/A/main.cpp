#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
vector<int>g[100005];
vector<pii>ans;
bool vis[100005];
int dfs(int u)
{
    int cnt=0;
    vis[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        if(!vis[g[u][i]]&&dfs(g[u][i])%2==0)
        {
            ans.push_back(pii(u,g[u][i]));
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("oddfactor.in","r",stdin);
    freopen("oddfactor.out","w",stdout);
    int n,m;
    memset(vis,0,sizeof vis);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&dfs(i)%2==0) f=false;
    }
    if(f)
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }else{
        printf("-1\n");
    }
    return 0;
}
