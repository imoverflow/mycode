#include <iostream>
#include <stdio.h>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}
int main()
{
    long long n,a,b,p,q,ans=0;
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&p,&q);
    ans=max((n/a)*p+(n/b)*q-(n/(lcm(a,b)))*q,(n/a)*p+(n/b)*q-(n/(lcm(a,b)))*p);
    printf("%lld",ans);
    return 0;
}
