#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>g[300005];
bool vis[300005];
int n,x,y;
long long bfs1(int m)
{
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(m);
    long long cnt=0;
    vis[m]=true;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<g[t].size();i++)
        {
            if(!vis[g[t][i]]&&g[t][i]!=y)
            {
                vis[g[t][i]]=true;
                q.push(g[t][i]);
            }
        }
    }
    return cnt;
}
long long bfs2(int m)
{
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(m);
    long long cnt=0;
    vis[m]=true;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<g[t].size();i++)
        {
            if(!vis[g[t][i]]&&g[t][i]!=x)
            {
                vis[g[t][i]]=true;
                q.push(g[t][i]);
            }
        }
    }
    return cnt;
}
int main()
{
    cin>>n>>x>>y;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long a=bfs1(x);
    long long b=bfs2(y);
    long long ans=0;
    long long same=a+b-n;
    a-=same;
    b-=same;
    ans+=a*(a-1);
    ans+=b*(b-1);
    ans+=a*same*2;
    ans+=b*same*2;
    ans+=same*(same-1);
    ans+=b*a;
    cout<<ans<<endl;
    return 0;
}


