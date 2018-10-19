#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,s[100005],pre[100005];
int check(int x)
{
    int flag=0,z=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>x) return 0;
        else if(pre[i]-pre[flag]<=x)
        {
            continue;
        }
        else
        {
            flag=i-1;
            z++;
        }
    }
    if(z>m-1) return 0;
    else return 1;
}
int main()
{
    int sum=0;
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        sum+=s[i];
        pre[i]=sum;
    }
    int l=0,r=sum,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
