#include <iostream>
#include <stdio.h>
using namespace std;
char ar[500005];
int s[500005];
int pre[500005]={0};
int bac[500005]={0};
int main()
{
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%c",&ar[i]);
        if(ar[i]=='B')
            sum+=s[i];
    }
    long long ma=0;
    for(int i=1;i<=n;i++)
    {
        if(ar[i-1]=='A')
            pre[i]=pre[i-1]+s[i-1];
        else
            pre[i]=pre[i-1]-s[i-1];
        ma=max((long long)pre[i],ma);
    }
    for(int i=n;i>=1;i--)
    {
        if(ar[i-1]=='A')
            bac[i]=bac[i+1]+s[i-1];
        else
            bac[i]=bac[i+1]-s[i-1];
        ma=max((long long)bac[i],ma);
    }
    printf("%lld\n",max(sum+ma,sum));
    return 0;
}
