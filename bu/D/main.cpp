#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int vis[100005];
const int mod=1e9+7;
vector<int>aa;
vector<int>bb;
int cnt;
int dfs(int v,int* s)
{
    if(vis[v]==false)
    {
        cnt++;
        vis[v]=true;
        dfs(s[v],s);
    }
    else
        return cnt;
}
int main()
{
    int n,m;
    int cases=1;
    while(~scanf("%d%d",&n,&m))
    {
        aa.clear();
        bb.clear();
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
        {
            cnt=0;
            if(!vis[a[i]])
            {
                aa.push_back(dfs(i,a));
            }
        }
        memset(vis,0,sizeof vis);
        for(int i=0;i<m;i++)
        {
            cnt=0;
            if(!vis[b[i]])
            {
                bb.push_back(dfs(i,b));
            }
        }
        long long ans=1;
        for(int i=0;i<aa.size();i++)
        {
            long long t=0;
            for(int j=0;j<bb.size();j++)
            {
                if(aa[i]%bb[j]==0)
                    t=(t+bb[j])%mod;
            }
            ans=ans*t%mod;
        }
        printf("Case #%d: %lld\n",cases++,ans);
    }
    return 0;
}
