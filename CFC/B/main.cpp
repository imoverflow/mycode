#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>g[100005];
bool vis[100005];
void bfs(int &l,int &r)
{
    l=0,r=0;
    queue<int>q1;
    queue<int>q2;
    q1.push(1);
    l++;
    vis[1]=true;
    while(q1.size())
    {
        int t=q1.front();
        q1.pop();
        for(int i=0;i<g[t].size();i++)
        {
            if(!vis[g[t][i]])
            {
                vis[g[t][i]]=true;
                q2.push(g[t][i]);
                r++;
            }
        }
        while(q2.size())
        {
            int t=q2.front();
            q2.pop();
            for(int i=0;i<g[t].size();i++)
            {
                if(!vis[g[t][i]])
                {
                    vis[g[t][i]]=true;
                    q1.push(g[t][i]);
                    l++;
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int l,r;
    bfs(l,r);
//    printf("%d %d\n",l,r);
    printf("%I64d\n",(long long)l*r-n+1);
    return 0;
}
