#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
bool vis[1000006]={false};
long long ans[1000006]={0};
int main()
{
//    long long sum=0;
//    for(int i=1;i<=1e3;i++)
//    {
////        if(!vis[i])
////        {
//            for(int j=1;j<=i;j++)
//            {
//                if(__gcd(i,j)==1)
//                for(int k=j;k<=i;k+=i)
//                {
//                    ans[i]+=(i/k+(i%k!=0))%mod;
//                }
//            }
////        }
//    }
//    for(int i=1;i<=10;i++)
//    {
//        printf("%lld\n",ans[i]);
//    }
    for(int k=1;k<=20;k++)
    {
        long long sum=0;
        for(int i=1;i<=k;i++)
        {
           for(int j=1;j<=i;j++)
           {
               sum+=(__gcd(i,j)==1)*(i/j+(i%j!=0));
           }
        }
        printf("%d %lld\n",k,sum);
    }
    int n;
    while(~scanf("%d",&n))
    {
//        printf("%lld\n",sum);
    }
    return 0;
}
