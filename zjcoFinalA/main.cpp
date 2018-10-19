#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b)
{
    return (a/__gcd(a,b))*b;
}
long long a,b,c,n;
long long check(long long m)
{
    long long x1=m/a;
    long long x2=m/b;
    long long x3=m/c;
    long long x4=m/lcm(a,b);
    long long x5=m/lcm(a,c);
    long long x6=m/lcm(b,c);
    long long x7=m/lcm(a,lcm(b,c));
    return m-((x1+x2+x3)-(x4+x5+x6)+x7);
}
int main()
{
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&n)!=EOF)
    {
        long long l=-1,r=1e18;
        long long ans=0;
        while(l+1<r)
        {
            long long mid=(l+r)/2;
            long long p=check(mid);
            if(p==n)
            {
                ans=mid;
                if(ans%a!=0&&ans%b!=0&&ans%c!=0)
                    break;
                else{
                    for(long long i=l;;i++){
                        if(check(i)==n&&i%a!=0&&i%b!=0&&i%c!=0)
                        {
                            ans=i;
                            break;
                        }
                    }
                    break;
                }
            }else if(p>n)
            {
                r=mid;
            }else{
                l=mid;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
