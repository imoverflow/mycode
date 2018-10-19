#include <iostream>
#include <stdio.h>
using namespace std;

double solve(long long a,long long b,long long c)
{
    if(a>b)
        return 1;
    if(a+c<=b)
        return 0;
    return (double)(c-(b-a))/(c+1);
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        printf("%.3f\n",solve(a,b,c));
    }
    return 0;
}
