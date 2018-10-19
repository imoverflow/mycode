#include <bits/stdc++.h>
using namespace std;

vector<short int>g1[1005];
vector<short int>g2[1005];
bool vis[1005];
int n,m;
set<int>ss;
void dfs1(int x)
{
    vis[x]=true;
    queue<short int>q;
    q.push(x);
    while(q.size())
    {
        int p=q.front();
        ss.insert(p);
        q.pop();
        for(int i=0;i<g1[p].size();i++)
        {
            if(!vis[g1[p][i]]){
                vis[g1[p][i]]=true;
                q.push(g1[p][i]);
            }
        }
    }
}
void dfs2(int x)
{
    vis[x]=true;
    queue<short int>q;
    q.push(x);
    while(q.size())
    {
        int p=q.front();
        ss.insert(p);
        q.pop();
        for(int i=0;i<g2[p].size();i++)
        {
            if(!vis[g2[p][i]]){
                vis[g2[p][i]]=true;
                q.push(g2[p][i]);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(g1,0,sizeof g1);
        memset(g2,0,sizeof g2);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g1[a].push_back(b);
            g2[b].push_back(a);
        }
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            ss.clear();
            memset(vis,0,sizeof vis);
            dfs1(i);
            if(ss.size()!=n)
            {
                memset(vis,0,sizeof vis);
                dfs2(i);
            }
            if(ss.size()!=n)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("I love you my love and our love save us!\n");
        else
            printf("Light my fire!\n");
    }
    return 0;
}
