#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> g[25];
vector<int>ss;
int tot=1;
bool vis[25];
void dfs(int st,int now,int time,vector<int> s)
{
    if(time==20&&(st==g[now][0]||st==g[now][1]||st==g[now][2]))
    {
        printf("%d: ",tot++);
        for(int i=0;i<s.size();i++)
        {
            printf(" %d",s[i]);
        }
        printf(" %d\n",st);
        return ;
    }else{
        for(int i=0;i<g[now].size();i++)
        {
            if(!vis[g[now][i]])
            {
                s.push_back(g[now][i]);
                vis[g[now][i]]=true;
                dfs(st,g[now][i],time+1,s);
                s.erase(--s.end());
                vis[g[now][i]]=false;
            }
        }
    }
    return ;
}
int main()
{
    for(int i=1;i<=20;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[i].push_back(a);
        g[i].push_back(b);
        g[i].push_back(c);
    }
    memset(vis,0,sizeof vis);
    int m;
    cin>>m;
    ss.clear();
    if(m==0)
    {
        return 0;
    }else{
        ss.push_back(m);
        vis[m]=1;
        dfs(m,m,1,ss);
    }
    return 0;
}
