#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,s[1005],dp[1005];
    while(scanf("%d",&t)!=EOF&&t!=0)
    {
        int sum=0,sum1=0;
        for(int i=0;i<t;i++)
            cin>>s[i];
        int res=0;
        for(int i=0;i<t;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(s[j]<s[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]==1)
                sum=max(s[i],sum);
            else
                if(dp[i]>dp[i-1])
                    sum+=s[i];

        }
        printf("%d\n",sum);
    }
    return 0;
}
