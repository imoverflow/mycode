#include <iostream>
#include <stdio.h>
using namespace std;
long long a,b,ans=0;
long long cal(long long x,long long c)
{
    long long sum=0;
    for(long long i=1,j=1;i<=x;i++,j*=2)
    {
        if(i==c)
            continue;
        sum+=j;
    }
    return sum;
}
void solve()
{
    for(long long i=2;i<=63;i++)
    {
        for(long long j=1;j<i;j++)
        {
            long long num=cal(i,j);
            if(num>=a&&num<=b)
                ans++;
        }

    }
}
int main()
{

    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        ans=0;
        solve();
        printf("%lld\n",ans);
    }
    return 0;
}
