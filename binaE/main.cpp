#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;
int l,n,m,d[500005];
int check(int x)
{
    int z=0,flag=0;
    for(int i=1;i<=n+1;i++)
    {
        if(d[i]-d[flag]<x)
        {
            //s[i+1]+=s[i];
            //s[i]=INF;
            z++;
        }else
        {
            flag=i;
        }
    }
    if(z>m) return 0;
    else return 1;

}
int main()
{
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        int mind=INF,maxd=0,a;
        d[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i];
        }
        sort(d+1,d+n+1);
        d[n+1]=l;
        mind=0;
        maxd=l;
        int l=mind,r=maxd,ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
