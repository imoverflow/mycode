#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
class DivFreed2
{
public:
    int dp[15][100005];
    int count(int n, int k)
    {
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            dp[0][i]=1;
            sum++;
        }
        for(int i=1;i<n;i++)
        {
            long long s=0;
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=sum;
                for(int z=j+j;z<=k;z+=j)
                {
                    dp[i][j]=(dp[i][j]-dp[i-1][z]+mod)%mod;
                }
                s=(s+dp[i][j])%mod;
            }
            sum=s;
        }
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};
//int dp[15][100005];
//int main()
//{
//    int n,k;
//    scanf("%d%d",&n,&k);
//    int sum=0;
//    for(int i=1;i<=k;i++)
//    {
//        dp[0][i]=1;
//        sum++;
//    }
//    for(int i=1;i<n;i++)
//    {
//        long long s=0;
//        for(int j=1;j<=k;j++)
//        {
//            dp[i][j]=sum;
//            for(int z=j+j;z<=k;z+=j)
//            {
//                dp[i][j]=(dp[i][j]-dp[i-1][z]+mod)%mod;
//            }
//            s=(s+dp[i][j])%mod;
//        }
//        sum=s;
//    }
//    int ans=0;
//    for(int i=1;i<=k;i++)
//    {
//        ans=(ans+dp[n-1][i])%mod;
//    }
//    printf("%d\n",ans);
//    return 0;
//}
//int dp[15][100005];
//int main()
//{
//    int n,k;
//    scanf("%d%d",&n,&k);
//    int sum=0;
//    for(int i=1;i<=k;i++)
//    {
//        dp[0][i]=1;
//        sum++;
//    }
//    for(int i=1;i<n;i++)
//    {
//        long long s=0;
//        for(int j=1;j<=k;j++)
//        {
//            dp[i][j]=sum;
//            for(int z=j+j;z<=k;z+=j)
//            {
//                dp[i][j]=(dp[i][j]-dp[i-1][z]+mod)%mod;
//            }
//            s=(s+dp[i][j])%mod;
//        }
//        sum=s;
//    }
//    int ans=0;
//    for(int i=1;i<=k;i++)
//    {
//        ans=(ans+dp[n-1][i])%mod;
//    }
//    printf("%d\n",ans);
//    return 0;
//}
//int dp[15][100005];
//int main()
//{
//    int n,k;
//    scanf("%d%d",&n,&k);
//    int sum=0;
//    for(int i=1;i<=k;i++)
//    {
//        dp[0][i]=1;
//        sum++;
//    }
//    for(int i=1;i<n;i++)
//    {
//        long long s=0;
//        for(int j=1;j<=k;j++)
//        {
//            dp[i][j]=sum;
//            for(int z=j+j;z<=k;z+=j)
//            {
//                dp[i][j]=(dp[i][j]-dp[i-1][z]+mod)%mod;
//            }
//            s=(s+dp[i][j])%mod;
//        }
//        sum=s;
//    }
//    int ans=0;
//    for(int i=1;i<=k;i++)
//    {
//        ans=(ans+dp[n-1][i])%mod;
//    }
//    printf("%d\n",ans);
//    return 0;
//}
