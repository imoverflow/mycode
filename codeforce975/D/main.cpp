#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<long long,set<int> > ma;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        int x,vx,vy;
        scanf("%d%d%d",&x,&vx,&vy);
        ma[a*vx-vy].insert(i);
    }
    long long ans=0;
    for(map<long long,set<int> >::iterator it=ma.begin();it!=ma.end();it++)
    {
        ans+=(long long)it->second.size()*(it->second.size()-1);
    }
    cout<<ans<<endl;
    return 0;
}
