#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;
long long n,k;
long long s[100005],c[100005];
double t[100005];
bool cmp(const double &a,const double &b)
{
    return a>b;
}
bool check(double mid)
{
    for(int i=0;i<n;i++)
    {
        t[i]=s[i]*c[i]-s[i]*mid;
    }
    sort(t,t+n,cmp);
    double sum=0;
    for(int i=0;i<n-k;i++)
    {
        sum+=t[i];
    }
    return sum>=0;
}
int main()
{
    while(~scanf("%lld%lld",&n,&k))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&s[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&c[i]);
        }
        double l=0,r=1e12;
        while(r-l>eps)
        {
            double mid=(l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        printf("%.10f\n",l);
    }
    return 0;
}

/*
3 1
1 10 100
1 2 3
*/
