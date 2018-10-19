#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if(b-a>=5)
        printf("0\n");
    else{
        long long ans=1;
        for(long long i=a+1;i<=b;i++)
        {
            ans=(ans*i)%10;
        }
        printf("%I64d\n",ans%10);
    }
    return 0;
}
