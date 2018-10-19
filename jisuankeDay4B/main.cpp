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
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        ma[pii(c-a,d-b)]++;
        q.push(pii(c-a,d-b));
    }
    int md=0;
    pii ans;
    ans.first=0;
    ans.second=0;
    while(q.size())
    {
        pii p=q.front();
        q.pop();
        if(ma[p]>md)
        {
            ans.first=p.first;
            ans.second=p.second;
            md=ma[p];
        }
    }
    printf("%lld %lld",ans.first,ans.second);
    return 0;
}
