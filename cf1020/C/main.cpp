#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<int>v[3005];
vector<int>vv;
int cnt[3005];
int cntt;
bool check()
{
    cntt=0;
    bool flag=true;
    int maxd=1;
    vv.clear();
    for(int i=2;i<=n;i++)
    {
        if(cnt[maxd]<cnt[i])
        {
            vv.clear();
            cntt=1;
            vv.push_back(i);
            maxd=i;
        }else if(cnt[maxd]==cnt[i])
        {
            cntt++;
            vv.push_back(i);
        }
    }
    return cnt[1]+cntt<cnt[maxd];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cnt[a]++;
        q.push(make_pair(b,a));
    }
    int flag=1;
    for(int i=2;i<=n;i++)
    {
        if(cnt[i]>=cnt[1])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        printf("0\n");
        return 0;
    }
    long long ans=0;
    while(check())
    {
        pair<int,int>p=q.top();
        q.pop();
        ans+=p.first;
        cnt[1]++;
        cnt[p.second]--;
    }
//    cout<<ans<<endl;
    long long res1=0;
    cntt++;
    while(q.size())
    {
        if(cntt)
        {
            res1+=q.top().first;
            cntt--;
        }
        v[q.top().second].push_back(q.top().first);
        q.pop();
    }
//    cout<<res1<<endl;
    long long res2=0;
    for(int i=0;i<vv.size();i++)
    {
        res2+=v[vv[i]][0];
    }
//    cout<<res2<<endl;
    printf("%I64d\n",min(ans+res1,ans+res2));
    return 0;
}
