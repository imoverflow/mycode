#include <iostream>
#include <stdio.h>
#define INF 1000000000
using namespace std;

int main()
{
//    int dp[200]={1};
//    int res=0;
//    int n;
//    scanf("%d",&n);
//    int s[100];
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d",&s[i]);
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<i;j++)
//        {
//            if(s[i]>s[j])
//                dp[i]=max(dp[i],dp[j]+1);
//        }
//        res=max(res,dp[i]);
//    }
//    printf("%d",res);
//    return 0;
    int dp[200]={1};
    int res=0;
    int n;
    scanf("%d",&n);
    int s[100];
    fill(dp,dp+n,INF);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=0;i<n;i++)
    {
        *lower_bound(dp,dp+n,s[i])=s[i];
    }
    printf("%d",lower_bound(dp,dp+n,INF)-dp);
}
