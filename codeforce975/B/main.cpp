#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long s[16];
long long solve(int x)
{
    if(s[x]==0) return 0;
    long long t[16];
    for(int i=0;i<14;i++)
    {
        t[i]=s[i];
    }
    long long p=t[x];
    t[x]=0;
    if(p<=14)
    {
        for(int i=(x+1)%14;;i=(i+1)%14)
        {
            if(!p) break;
            t[i]+=1;
            p--;
        }
    }else{
        for(int i=0;i<14;i++)
        {
            t[i]+=p/14;
        }
        int re=p%14;
        for(int i=(x+1)%14;;i=(i+1)%14)
        {
            if(!re) break;
            t[i]+=1;
            re--;
        }
    }
    long long ans=0;
    for(int i=0;i<14;i++)
    {
        if(t[i]%2==0)
        {
            ans+=t[i];
        }
    }
    return ans;
}
int main()
{
    for(int i=0;i<14;i++)
    {
        scanf("%I64d",&s[i]);
    }
    long long ans=0;
    for(int i=0;i<14;i++)
    {
        ans=max(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}
