#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<long long,long long>ma;
vector<pair<long long,long long> >g[160005];
set<long long>ss;
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        long long a;
        scanf("%I64d",&a);
        ss.insert(a);
        if(ma[a]==0)
        {
            ma[a]=cnt;
            g[cnt++].push_back(make_pair(i,a));
        }else{
            g[ma[a]].push_back(make_pair(i,a));
        }
    }
    for(auto i:ss)
    {
        int x=ma[i];
        sort(g[x].begin(),g[x].end());
        while(g[x].size()>=2)
        {
            g[x].erase(g[x].begin());
            if(ma[g[x][0].second*2]==0)
            {
                ss.insert(g[x][0].second*2);
                ma[g[x][0].second*2]=cnt;
                g[cnt++].push_back(make_pair(g[x][0].first,g[x][0].second*2));
            }else{
                g[ma[g[x][0].second*2]].push_back(make_pair(g[x][0].first,g[x][0].second*2));
            }
            g[x].erase(g[x].begin());
        }
    }
    vector<pair<long long,long long> >ans;
    for(int i=1;i<cnt;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            ans.push_back(make_pair(g[i][j].first,g[i][j].second));
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        printf("%I64d ",ans[i].second);
    }
    return 0;
}
