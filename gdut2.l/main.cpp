#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e,s[1005]={0},dp[1005];
    while(scanf("%d",&a)!=EOF&&a!=0)
    {
        int sum=0;
        for(int i=1;i<=a;i++)
        {
            scanf("%d",&s[i]);
        }
        s[0]=0;
        memset(dp,0,sizeof(dp));
        dp[a]=1;
        for(int i=a;i>=0;i--)
            for(int j=i;j<=a;j++)
                if(s[i]<s[j])
                    dp[j]=max(dp[j],dp[j+1]+1);
                else
                    dp[j]=dp[j+1];
        for(int i=0;i<=a;i++)
            printf("%d ",dp[i]);
        for(int i=1,j=1;i<=a+1;i++)
        {
            if(dp[j-1]-1==dp[i])
            {
                sum+=s[i-1];
                j=i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
