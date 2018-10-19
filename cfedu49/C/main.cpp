#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int vis[10005];
vector<int>v;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof vis);
        v.clear();
        for(int i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            if(vis[a])
            {
                v.push_back(a);
                vis[a]=0;
            }
            else
            {
                vis[a]=1;
            }
        }
        int ans1,ans2;
        sort(v.begin(),v.end());
        double res=1e15;
        for(int i=0; i<v.size()-1; i++)
        {
            long long p=2*(v[i]+v[i+1]);
            long long s=1ll*v[i]*v[i+1];
            if(res>1.0*p*p/s)
            {
                res=1.0*p*p/s;
                ans1=v[i];
                ans2=v[i+1];
            }
        }
        printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
    }
    return 0;
}
