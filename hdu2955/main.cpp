#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int num,p,n;
        double P,m;
        int dp[105][105],cash[105],risk[105];
        scanf("%lf%d",&P,&num);
        p=P*100000;
        for(int i=0;i<num;i++)
        {
            scanf("%d%lf",&cash[i],&m);
            n=m*100000;
            risk[i]=n;
        }
        memset(dp,0,sizeof(dp));
        //dp[0][0]=0;
        for(int i=num-1;i>=0;i--)
        {
            for(int j=0;j<=p;j++)
            {
                if(j<risk[i])
                    dp[i][j]=dp[i+1][j];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j-risk[i]]+cash[i]);
            }
        }
        printf("%d\n",dp[0][p]);
    }
    return 0;
}
