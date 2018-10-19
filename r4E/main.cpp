#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        int s[1005],a[1005];
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(int i=0;i<m;i++)
        {
            scanf("%d",&s[i]);
            a[s[i]]=1;
        }
        sort(s,s+m);
        int ans=0;
        for(int i=n*m,j=m-1,z=1;i>z;i--)
        {
            if(a[i]==1)
            {
                j--;
                continue;
            }
            if(i>s[j])
            {
                ans++;
                j--;
            }else
            {
                for(int k=0;k<n;k++)
                {
                    while(a[z]!=1)
                    {
                        z++;
                    }
                    a[z]=1;
                }
                j--;
            }
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
