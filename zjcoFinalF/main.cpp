#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,s[1005];
    while(scanf("%lld",&n)!=EOF)
    {
        long long x=0;
        long long sum=0,a=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&s[i]);
            x^=s[i];
        }
        for(int i=0;i<n;i++)
        {
            a=x^s[i];
            if(a<s[i])
                sum++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
