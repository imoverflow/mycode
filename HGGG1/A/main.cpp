#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long s[100006];
pair<long long,long long> t[1000006];

int main()
{
    t[3].first=1;
    t[3].second=1;
    t[4].first=1;
    t[4].second=3;
    for(int i=5;i<1000005;i++)
    {
        t[i].first=t[i-2].first+1;
        t[i].second=t[i-2].second+2;
    }
//    for(int i=3;i<10;i++)
//    {
//        printf("%lld %lld\n",t[i].first,t[i].second);
//    }
    int n;
    scanf("%d",&n);
    long long ans=0;
    int mind=1e9+1;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&s[i]);
    }
    sort(s,s+n);
    if(n==1)
        printf("%I64d\n",s[0]);
    else if(n==2)
        printf("%I64d\n",s[1]);
    else if(n==3)
        printf("%I64d\n",s[0]+s[1]+s[2]);
    else{

        ans+=t[n].first*s[0];
        ans+=t[n].second*s[1];
//        printf("%d %d",t[n].first,t[n].second);
        for(int i=n-1;i>=2;i-=2)
        {
            ans+=s[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
