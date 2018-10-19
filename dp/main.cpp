#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//hdu2084
int main()
{
    int s[105][105];
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
                scanf("%d",&s[i][j]);
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                s[i][j]+=max(s[i+1][j],s[i+1][j+1]);
            }
        }
        printf("%d\n",s[0][0]);
    }
    return 0;
}
