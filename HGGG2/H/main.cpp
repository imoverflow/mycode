#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    long long s,t;
}s[200005];
bool cmp(const node &a,const node &b)
{
    return a.s<b.s;
}
int main()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%lld%lld",&s[i].s,&s[i].t);
    }
    sort(s,s+k,cmp);
    long long ans=0;
    long long now=s[0].t;
    ans+=s[0].s-1;
    for(int i=1;i<k;i++)
    {
        if(s[i].s>now)
        {
            ans+=s[i].s-now-1;
            now=s[i].t;
        }
    }
    ans+=n-now;
    printf("%lld\n",ans);
    return 0;
}
