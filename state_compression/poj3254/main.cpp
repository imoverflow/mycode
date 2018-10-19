#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int s[15];
int state_count;
int dp[1<<13][15];
int state[1<<13];
int n,m;
bool check(int i)
{
    if((i&(i<<1))!=0) return false;
    return true;
}
void init()
{
    state_count=0;
    int tot=1<<n;
    for(int i=0;i<tot;i++)
    {
        if(check(i))
            state[state_count++]=i;
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    memset(s,0,sizeof s);
    memset(dp,0,sizeof dp);
    for(int i=0;i<m;i++)
    {
        int res=0;
        for(int j=0;j<n;j++)
        {
            int a;
            scanf("%d",&a);
            if(a==0)
                res+=(1<<(n-j-1));
        }
        s[i]=res;
    }
    init();
    for(int i=0;i<state_count;i++)
    {
        if((state[i]&s[0])==0)
            dp[i][0]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<state_count;j++)
        {
            if((s[i]&state[j])==0)
            {
                for(int k=0;k<state_count;k++)
                {
                    if(((s[i-1]&state[k])==0)&&((state[k]&state[j])==0))
                        dp[j][i]=(dp[j][i]+dp[k][i-1])%100000000;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<state_count;i++)
    {
        ans=(ans+dp[i][m-1])%100000000;
    }
    printf("%d\n",ans);
    return 0;
}
