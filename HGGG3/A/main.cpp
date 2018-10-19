#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            long long a,b;
            scanf("%lld%lld",&a,&b);
            ans+=a*b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
