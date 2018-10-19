#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long s[1000005];
long long pre[1000005];
int main()
{
    s[1]=1;
    for(int i=2;i<=1e6;i++)
        s[i]=i;
    for(int i=2;i<=1e6;i++)
    {
        if(s[i]==i)
        {
            for(int j=i;j<=1e6;j+=i)
            {
                s[j]=s[j]/i*(i-1);
            }
        }
        pre[i]=pre[i-1]+s[i];
    }
    int n;
    while(~scanf("%d",&n)&&n)
    {
        printf("%lld\n",pre[n]);
    }

    return 0;
}
