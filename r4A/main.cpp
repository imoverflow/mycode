#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int s[100005];
long long co(long long n,long long k)
{
    return n*(n-1)/k;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        int ans=0;
        if(abs(s[0]-s[n-1])<=k&&n>=2)
            printf("%lld\n",co(n,2));
        else if(s[0]<=k&&n==1)
            printf("1\n");
        else if(s[0]>k&&n==1)
            printf("0\n");
        else
        {
            int i=0,l1=0,r1=n-1,an=1000000000;
            while(abs(s[i]-s[n-1])>k&&i<n-1)
            {
                l1=i;
                r1=n-1;
                an=1000000000;
                while(l1<r1)                                  //¶þ·ÖÓÒ±ß½ç
                {
                    int mid=(l1+r1)/2;
                    if(abs(s[i]-s[mid])>k)
                        r1=mid;
                    if(abs(s[i]-s[mid])<=k)
                        l1=mid+1;
                }
                ans+=n-r1;
                i++;
            }
            printf("%lld\n",co(n,2)-ans);
        }
    }
    return 0;
}
