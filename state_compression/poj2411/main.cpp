#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int n,m;
bool testfirst(int x)
{
    int i=0;
    while(i<m)
    {
        if(x&(1<<i))
        {
            if(i==m-1||(x&(1<<(i+1)))==0)
                return false;
            i+=2;
        }else{
            i++;
        }
    }
    return true;
}
bool cp(int cur,int pre)
{
    int i=0;
    while(i<m)
    {
        if(cur&(1<<i))
        {
            if(!(pre&(1<<i)))
                i++;
            else if((pre&(1<<(i+1)))&&(cur&(1<<(i+1)))&&i!=m-1)
                i+=2;
            else
                return false;
        }else{
            if(pre&(1<<i))
                i++;
            else
                return false;
        }
    }
    return true;
}
long long dp[15][1<<15];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        memset(dp,0,sizeof dp);
        if((n*m)%2!=0)
        {
            printf("0\n");
            continue;
        }
        int tot=1<<m;
        for(int i=0;i<tot;i++)
        {
            if(testfirst(i))
            {
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<tot;j++)
            {
                for(int k=0;k<tot;k++)
                {
                    if(dp[i-1][k]!=0){
                        if(cp(j,k))
                            dp[i][j]+=dp[i-1][k];
                    }
                }
            }
        }
        printf("%lld\n",dp[n-1][tot-1]);
    }
    return 0;
}
