#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int head[200005];
vector<int>g[200005];
//int s[600005];
int c,p,x,l;
int sdeg[200005];
int fdeg[200005];
bool vis[200005];
void init()
{
    memset(fdeg,0,sizeof fdeg);
    memset(sdeg,0,sizeof sdeg);
    memset(vis,0,sizeof vis);
    for(int i=0;i<=c;i++)
        g[i].clear();
}
bool dfs(int v)
{
    queue<int>qq;
    qq.push(v);
    vis[v]=true;
    while(!qq.empty())
    {
        int zz=qq.front();
        qq.pop();
        int len=g[zz].size();
        for(int i=0;i<len;i++)
        {
            if(!vis[g[zz][i]])
            {
                fdeg[g[zz][i]]--;
                if(sdeg[g[zz][i]]>=fdeg[g[zz][i]]*2)
                {
                    if(vis[g[zz][i]]==false)
                    {
                        qq.push(g[zz][i]);
                        vis[g[zz][i]]=true;
                    }
                }
            }
        }
    }
    if(vis[x]==false)
        return false;
    else
        return true;
}
int main()
{
    while(~scanf("%d%d%d%d",&c,&p,&x,&l))
    {
        init();
        for(int i=0;i<p*2;i+=2)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
            sdeg[a]++;
            sdeg[b]++;
            fdeg[a]++;
            fdeg[b]++;
        }
        if(dfs(l)==false)
        {
            printf("stay\n");
        }else{
            printf("leave\n");
        }
    }
    return 0;
}
