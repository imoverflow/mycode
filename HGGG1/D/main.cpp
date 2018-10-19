#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int s[400005];
vector<int>g[400005];
int n,m,k;
void dfs(int x,int cnt)
{
    s[x]=cnt;
    for(int i=0;i<g[x].size();i++)
    {
        if(s[g[x][i]]==-1)
            dfs(g[x][i],cnt%k+1);
    }
}
int main()
{
    fill(s,s+40005,-1);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m!=0&&k==1){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]==-1) dfs(i,1);
        printf("%d\n",s[i]);
    }
}
