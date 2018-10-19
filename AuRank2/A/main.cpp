#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("popcorn.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans1=1,ans2=1,ans3=1;
        for(int i=1;i<=n;i++)
        {
            ans1*=i;
        }
        for(int i=1;i<=k;i++)
        {
            ans2*=i;
        }
        for(int i=1;i<=n-k;i++)
        {
            ans3*=i;
        }
        printf("%lld\n",ans1/ans2/ans3);
    }
    return 0;
}
