#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,s[100005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        int sum=0;
        if(n%2==1)
        {
            for(int i=0;i<n;i++)
            {
                if(i==n/2) continue;
                sum+=(s[n/2]-s[i])*(s[n/2]-s[i]);
            }
            printf("%d\n",sum);
        }else{
            int sum1=0,sum2=0;
            for(int i=0;i<n;i++)
            {
                if(i==n/2-1) continue;
                sum1+=(s[n/2-1]-s[i])*(s[n/2-1]-s[i]);
            }
            for(int i=0;i<n;i++)
            {
                if(i==n/2) continue;
                sum2+=(s[n/2]-s[i])*(s[n/2]-s[i]);
            }
            printf("%d\n",min(sum1,sum2));
        }
    }
    return 0;
}
