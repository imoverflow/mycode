#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

long long c[2005][2005];
int main()
{
    freopen("problem.in","r",stdin);
    freopen("problem.out","w",stdout);
    int t,k;
    memset(c,0,sizeof(c));
    scanf("%d%d",&t,&k);
    for(int i=0;i<=2000;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
        }
    }
    long long ans=0;
    for(int i=0;i<t;i++){
        int m,n;
        scanf("%d%d",&n,m);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i,m);j++)
            {
                if(c[i][j]%k==0)
                    ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
