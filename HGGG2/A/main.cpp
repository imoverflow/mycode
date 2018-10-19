#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[100];
int dp[200];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int res=0;
    for(int i=0;i<len;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(s[j]<s[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    printf("%d\n",26-res);
    return 0;
}
