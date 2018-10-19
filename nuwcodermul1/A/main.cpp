#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

long long C[2005][2005];

int main()
{
    C[0][0]=1;
    for(int i=1; i<2005; i++)
    {
        C[i][0]=1;
        for(int j=0; j<=i; j++)
        {
            if(j==0)
                C[i][j]=C[i-1][j];
            else
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
//    C[0][0]=1;
//    for(int i=1;i<=2000;i++)
//    for(int j=0;j<=min(i,1000);j++)
//    C[i][j]=(C[i-1][j]+(j>0?C[i-1][j-1]:0))%MOD;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        printf("%lld\n",C[n+m][n]*C[n+m][n]%MOD);
        printf("%lld\n",C[n+m][m-1]*C[n+m][n-1]%MOD);
        printf("%lld\n",((C[n+m][n]*C[n+m][n]%MOD)+MOD-C[n+m][m-1]*C[n+m][n-1]%MOD)%MOD);
    }
    return 0;
}
