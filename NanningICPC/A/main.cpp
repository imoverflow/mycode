#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int s[200010];
int v[200010];
int dp[200010];
int weight(int n)
{
    if(n>=10000)
        return 5;
    else if(n<0)
        return 0;
    else
        return 1;
}
int main()
{
    freopen("a.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cnt=0;
    int n;
    while(~scanf("%d",&n))
    {
        s[cnt]=n;
        if(n<0) v[cnt++]=0;
        else if(n>=10000){
            v[cnt++]=5;
//            s[cnt++]-=10000;
        }else{
            v[cnt++]=1;
        }
    }
    fill(dp,dp+cnt,INF);
    long long ans=0;
    for(int i=0,j=0;i<cnt;i++)
    {
 //       *lower_bound(dp,dp+cnt,s[i]-(s[i]>=10000)*10000)=s[i]-(s[i]>=10000)*10000;
        if(upper_bound(dp,dp+cnt,s[i]-(s[i]>=10000)*10000)-dp==j)
        {
            ans+=v[i];
            j++;
        }else{
            ans-=weight(*upper_bound(dp,dp+cnt,s[i]-(s[i]>=10000)*10000));
            ans+=v[i];
        }
        *upper_bound(dp,dp+cnt,s[i]-(s[i]>=10000)*10000)=s[i]-(s[i]>=10000)*10000;
    }
    printf("%lld\n",ans);
    return 0;
}
