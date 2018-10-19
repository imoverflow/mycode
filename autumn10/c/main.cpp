#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

long long s[100005];
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        memset(s,0,sizeof s);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&s[i]);
        }
        s[n+1]=1e18;
        long long ans=1;
        long double v=s[n]-s[n-1];
        for(int i=n-1;i>=1;i--)
        {
            if(s[i]-s[i-1]>v+1e-8)
            {
                int p=ceil(1.0*(s[i]-s[i-1]-1e-8)/v);
                ans+=p;
                v=1.0*(s[i]-s[i-1])/p;
            }else{
                ans+=1;
                v=(s[i]-s[i-1]);
            }
        }
        printf("Case #%d: %lld\n",cas++,ans);

    }
    return 0;
}
