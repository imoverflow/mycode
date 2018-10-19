#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool vis[1005];
vector<int>g[1005];
int main()
{
    memset(vis,0,sizeof vis);
    int n;
    scanf("%d",&n);
    int maxa=0;
    int index=0;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        if(m>maxa)
        {
            maxa=m;
            index=i;
        }
        for(int j=0;j<m;j++)
        {
            int a;
            scanf("%d",&a);
            if(a==i)
                flag=false;
            g[i].push_back(a);
        }
    }
    if(flag==false)
    {
        printf("NO\n");
        return 0;
    }
    set<pair<int,int> >ss;
    queue<int>q;
    vis[index]=true;
    for(int i=0;i<g[index].size();i++)
    {
        ss.insert(make_pair(index,g[index][i]));
        q.push(g[index][i]);
//        vis[g[index][i]]=true;
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(int i=0;i<g[u].size();i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[j]==true)
                    ss.erase(make_pair(j,g[u][i]));
            }
            ss.insert(make_pair(u,g[u][i]));
            if(vis[g[u][i]]!=true)
                q.push(g[u][i]);
        }
    }
    if(ss.size()==n-1)
    {
        printf("YES\n");
        for(set<pair<int,int> >::iterator it=ss.begin();it!=ss.end();it++)
        {
            printf("%d %d\n",(*it).first,(*it).second);
        }
    }else{
        printf("NO\n");
//        for(set<pair<int,int> >::iterator it=ss.begin();it!=ss.end();it++)
//        {
//            printf("%d %d\n",(*it).first,(*it).second);
//        }
    }
    return 0;
}
