#include <iostream>
#include <stdio.h>
using namespace std;
int dp[1000005]={0};
int is(int t)
{
    while(t>0)
    {
        if(t%100==13)
        {
            return 1;
        }
        t/=10;
    }
    return 0;
}
int main()
{
    int n;
    dp[0]=1;
    for(int i=1,j=1;i*13<=10000000;i++)
    {
        if(is(i*13))
        {
            dp[j++]=i*13;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        int i=1;
        while(n>=dp[i])
        {
            i++;
        }
        printf("%d\n",i-1);
    }
    return 0;
}
