#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n;
double r,z;
double power[100005];
vector<pair<int,int> >g[100005];
double bfs()
{
    double ans=0;
    power[0]=z;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int fa;
        fa=q.front();
        q.pop();
        for(int i=0;i<g[fa].size();i++)
        {
            if(g[fa][i].first==fa)
            {
                power[fa]*=g[fa][i].second;
                ans+=power[fa];
            }else{
                q.push(g[fa][i].first);
            }
        }
        for(int i=0;i<g[fa].size();i++)
        {
            if(g[fa][i].first!=fa)
            {
                power[g[fa][i].first]=power[fa]*(1-r);
            }
        }
    }
    return ans;
}
int main()
{
    scanf("%lld%lf%lf",&n,&z,&r);
    r/=100;
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==0)
        {
            int x;
            scanf("%d",&x);
            g[i].push_back(make_pair(i,x));
        }
        for(int j=0;j<k;j++)
        {
            int m;
            scanf("%d",&m);
            g[i].push_back(make_pair(m,0));
        }
    }
    double res=bfs();
    long long ans=(long long)res;
    printf("%d\n",ans);
    return 0;
}
