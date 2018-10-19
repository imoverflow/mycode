#include <iostream>
#include <stdio.h>
using namespace std;
int p[100005];
int q,n;
int mink()
{
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(sp(m)<=q)
        {
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i-0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    return 0;
}
