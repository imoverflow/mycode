#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>g[1005];

void dfs(int x)
{
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int ans=0;
        int v=q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++)
        {
            if(g[g[v][i]].size()==0)
                ans++;
            else
                q.push(g[v][i]);
        }
        if(ans<3)
        {
            printf("No\n");
            return ;
        }
    }
    printf("Yes\n");
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<n+1;i++)
    {
        int a;
        scanf("%d",&a);
        g[a].push_back(i);
    }
    dfs(1);
    return 0;
}
