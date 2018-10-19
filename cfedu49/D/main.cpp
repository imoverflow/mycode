#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int c[200005],s[200005];
int vis[200005];
vector<int> v;
vector<int> x;
map<int,int> ma;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long res=1e9;
        x.clear();
        ma.clear();
        int cnt1=0;
        if(!vis[i])
        {
            int p=i;
            while(!vis[p])
            {
                ma[p]=cnt1++;
                x.push_back(p);
                vis[p]=1;
                p=s[p];
                if(vis[p]==2)
                    goto label;
            }
            for(int i=ma[p];i<x.size();i++)
            {
                vis[x[i]]=2;
                res=min(res,(long long)c[x[i]]);
            }
            ans+=res;
        }
        label:
            ;
    }
//    for(int i=1;i<=n;i++)
//    {
//        if(vis[i]!=2)
//        {
//            ans+=c[i];
//        }
//    }
    printf("%I64d\n",ans);
    return 0;
}
