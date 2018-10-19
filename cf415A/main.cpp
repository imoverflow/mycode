#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

long long n,k,ave,sum=0;
long long check(long long num){
    return min(k,(long long)(((double)sum+num*k)/(double)(n+num)+0.5));
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%lld",&a);
        sum+=a;
    }
    long long l=0,r=50000;
    while(l+1<r)
    {
        long long mid=(l+r)/2;
        if(check(mid)>=k)
            r=mid;
        else
            l=mid;
    }
    printf("%lld\n",r);
    return 0;
}
