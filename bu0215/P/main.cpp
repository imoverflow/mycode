#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long>g;
int n;
bool check(long long a)
{
    long long x=sqrt(a);
    if(x*x==a) return true;
    else if((x+1)*(x+1)==a) return true;
    else if((x-1)*(x-1)==a) return true;
    else return false;
}
void init()
{
    long long lim=1e18;
    for(int i=2;i<=1e6;i++)
    {
        double a=1;
        long long res=i;
        for(int j=2;j<=64;j++)
        {
            if(lim/res<i) break;
            res*=i;
            if(j&1&&!check(res))
                g.push_back(res);
        }
    }
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
}
int main()
{
    int t;
    init();
//    cout<<g[0]<<endl;
//    return 0;
    cin>>t;
    while(t--)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        long long res1=upper_bound(g.begin(),g.end(),b)-lower_bound(g.begin(),g.end(),a);
        long long res2=(long long)(sqrt(b)+0.00000000001)-(long long)(sqrt(a-1)+0.00000000001);
        printf("%I64d\n",res1+res2);
    }
    return 0;
}
