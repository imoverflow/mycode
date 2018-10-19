#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int who,power;
};
int g[1000][1000]={0};
bool used[1000][1000]={false};
typedef pair<int,pair<int,int> > pii;  //cost from to
set<int> mem;
priority_queue<pii> pp;
int main()
{
    int n,m;
    cin>>n>>m;
    memset(g,0,sizeof g);
    memset(used,0,sizeof used);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int> k;
        k.first=u,k.second=v;
        pp.push(pii(w,k));
        g[u][v]=w;
        g[v][u]=w;
    }
    queue<int> na;
    while(na.size())
        na.pop();
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)
            na.push(i);
    }
    int sum=0;
    int cnt=0;
    while(!na.empty())
    {
        int p=na.front();
        mem.insert(p);
        na.pop();
        int ma=0;
        int ind=0;
        for(int i=1;i<=n;i++)
        {
            if(g[p][i]>ma&&g[p][i]!=0){
                ind=i;
                ma=g[p][i];
            }
        }
        sum+=ma;
        if(ind !=0)
        {
            mem.insert(ind);
            used[p][ind]=true;
            used[ind][p]=true;
        }
    }
    double ans=(double)sum/(mem.size()*(2*n-mem.size()));
    while(pp.size())
    {
        double newans=0;
        pii k=pp.top();
        pp.pop();
        pair<int,int>z=k.second;
        int flag=0;
        if(used[z.first][z.second]==false)
            flag=1;
        if(flag==0) continue;
        used[z.first][z.second]=true;
        used[z.second][z.first]=true;
        sum+=k.first;
        mem.insert(z.first);
        mem.insert(z.second);
        newans=(double)sum/(mem.size()*(2*n-mem.size()));
        if(newans<ans)
            break;
        else
            ans=newans;
    }
    printf("%.4f",ans+0.00005);
    return 0;
}
