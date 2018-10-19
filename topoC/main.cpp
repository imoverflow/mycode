#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int ,int>p;
vector<int>g[10005];
int degree[10005];
long long topo(int n)
{
    long long ans=0;
//    memset(degree,0,sizeof(degree));
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<g[i].size();j++)
//        {
//            degree[g[i][j]]++;
//        }
//    }
    queue<pair<int,int> > q;
    int tot=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(degree[i]==0)
        {
            p.first=i,p.second=888;
            q.push(p);
        }
    }
    while(q.size())
    {
        pair<int,int>qq=q.front();
        q.pop();
        tot++;
        ans+=qq.second;
        for(int j=0;j<g[qq.first].size();j++)
        {
            degree[g[qq.first][j]]--;
            if(degree[g[qq.first][j]]==0)
            {
                p.second=qq.second+1;
                p.first=g[qq.first][j];
                q.push(p);
            }
        }
    }
    if(tot==n)
        return ans;
    else
        return 0;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(degree,0,sizeof(degree));
        memset(g,0,sizeof g);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            degree[a]++;
            g[b].push_back(a);
        }
        long long an=topo(n);
        if(an==0)
            puts("-1");
        else
        {
            printf("%lld\n",an);
        }
    }
    return 0;
}
