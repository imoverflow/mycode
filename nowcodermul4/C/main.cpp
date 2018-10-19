#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long sum[1000005];
int main()
{
    a[0]=0;
    a[1]=0;
    for(long long i=2;i<100;i++)
    {
        a[i]=a[i/2]+((i*(i+1)/2%2)==0?1:-1);
        sum[i]=sum[i-1]+abs(a[i]);
    }
    for(int i=1;i<100;i++)
    {
        printf("%3d:%10lld     %10lld %10lld %10lld\n",i,a[i],sum[i],sum[i]-i,sum[i]-sum[i-1]);
    }
    return 0;
}
