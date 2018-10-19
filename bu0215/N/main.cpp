#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    while(q--)
    {
        long long x;
        scanf("%I64d",&x);
        if(x%2==1)
        {
            printf("%I64d\n",(x+1)/2);
            continue;
        }
        long long m=n;
        long long a;
        while(x%2==0)
        {
            x=m-x/2;
            m=x;
        }
        printf("%I64d\n",n-x+(x+1)/2);
    }
    return 0;
}
