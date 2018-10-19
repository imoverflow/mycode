#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int locate[250];
int n,k;
bool check(int mid)
{
    int s[250];
    memset(s,0,sizeof s);
    for(int i=0;i<k;i++)
    {
        for(int j=max(locate[i]-(mid-1),1);j<=min(n,locate[i]+(mid-1));j++)
        {
            s[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=1)
            return false;
    }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d",&locate[i]);
        }
        int l=1,r=201;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
