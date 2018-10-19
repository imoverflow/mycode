#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        for(long long i=sqrt(a)*sqrt(b);i>0;i--)
        {
            if(b%i!=0||i%a!=0) continue;
            if(gcd((b/i)*a,i)==a)
            {
                printf("%lld %lld\n",i,(b/i)*a);
                break;
            }
        }
    }
    return 0;
}
