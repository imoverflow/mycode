#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(__gcd(a,b)==1)
        {
            printf("Nao\n");
        }else{
            printf("Sim\n");
        }
    }
    return 0;
}
