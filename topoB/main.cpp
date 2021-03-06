#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>g[110];
int degree[110];

int topo(int n)
{
    queue<int>q;
    memset(degree,0,sizeof(degree));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            degree[g[i][j]]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(degree[i]==0)
        {
            q.push(i);
        }
    }
    int tot=0;
    while(q.size())
    {
        int qq=q.front();
        q.pop();
        tot++;
        for(int i=0;i<g[qq].size();i++)
        {
            degree[g[qq][i]]--;
            if(degree[g[qq][i]]==0)
                q.push(g[qq][i]);
        }
    }
    if(tot==n)
        return 1;
    else
        return 0;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        memset(g,0,sizeof(g));
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        if(topo(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
