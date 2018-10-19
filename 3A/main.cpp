#include <iostream>
#include <stdio.h>
using namespace std;
int s[1000005]={0},dp[1000005]={0};
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d",&s[i]);
//    }
//    int res=0;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<i;j++)
//        {
//            if(gcd(s[j],s[i])!=1)
//            {
//                dp[i]=max(dp[i],dp[j]+1);
//            }
//        }
//        res=max(res,dp[i]);
//    }
//    printf("%d",res);
    int n,ma=0,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            dp[0]=1;
        }
        for(int j=1;j*j<=a;j++)
        {
            if(a%j==0)
            {
                if(j!=1)
                    dp[j]++;
                if(a/j!=j)
                    dp[a/j]++;
                if(dp[j]>dp[ma])
                    ma=j;
                if(dp[a/j]>dp[ma])
                    ma=a/j;
            }
        }
    }
    printf("%d",dp[ma]);
    return 0;
//    7
//56 9 8 4 2 4 1
}
