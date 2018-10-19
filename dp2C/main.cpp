#include <iostream>
#include <stdio.h>
using namespace std;
int dp[1000005]={0};
int is(int t)
{
    while(t>0)
    {
        if(t%2==1)
        {
            t/=10;
            continue;
        }
        if(t%10==4||t%100==62)
        {
            return 0;
            break;
        }
        t/=10;
    }
    return 1;
}
int main()
{
    int n,m;
    dp[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        dp[i]=dp[i-1]+is(i);
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        if(n!=m)
            printf("%d\n",dp[m]-dp[n]+is(n));
        else
            printf("%d\n",is(n));
    }
    return 0;
}
