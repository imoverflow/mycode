#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[1000006];
long long sum[1000006];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&s[i]);
            if(i>0)
                sum[i]=sum[i-1]+s[i];
            else
                sum[i]=s[i];
        }
        sort(s,s+n);
        printf("%lld\n",s[n-1]-s[0]);
    }
    return 0;
}
