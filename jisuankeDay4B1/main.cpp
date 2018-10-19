#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long>pii;
map<pii ,long long>ma;
queue<pii>q;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        ma[pii((long long)(c*1e6-a*1e6),(long long)(d*1e6-b*1e6)]++;
        q.push(pii((long long)(c*1e6-a*1e6),(long long)(d*1e6-b*1e6));
    }
    int md=0;
    pii ans1;
    ans.first=0;
    ans.second=0;
    pii ans2;
    ans.first=0;
    ans.second=0;
    pii ans3;
    ans.first=0;
    ans.second=0;
    while(q.size())
    {
        pii p=q.front();
        q.pop();
        if(ma[p]>md)
        {
            ans3.first=p.first;
            ans3.second=p.second;
            md=ma[p];
        }
    }
    printf("%lld %lld",ans.first,ans.second);
    return 0;
}
