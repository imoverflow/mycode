#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long xx[1000000];
long long mod=998244353;
long long quick(long long x,long long p)
{
    long long ans=1;
    while(p)
    {
        if(p&1) ans=ans*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return ans;
}

void init()
{
    xx[0]=1;
    xx[1]=3;
    for(int i=2;i<500005;i++)
    {
        xx[i]=(xx[i-1]*(2*i-1)*3%mod-(i-1)*xx[i-2]%mod)%mod*quick(i,mod-2)%mod;
        xx[i]%=mod;
        if(xx[i]<0) xx[i]+=mod;
    }
}

int main()
{
    init();
    int n;
    cin>>n;
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    n--;
    long long x1=xx[n];
    long long x2=xx[n-1];
    long long x3=xx[n+1];
    cout<<((-x2+6*x1-x3)%mod*quick(2,mod-2)%mod+mod)%mod<<endl;
    return 0;
}
