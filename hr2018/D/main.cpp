#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long s[100005];
long long t[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i+1]);
    }
//    sort(s,s+n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(r-l+1>90)
        {
            printf("Yes\n");
            continue;
        }
        bool flag=false;
        for(int i=0,j=l;j<=r;j++,i++)
        {
            t[i]=s[j];
        }
        sort(t,t+r-l+1);
        for(int i=0;i+2<=r-l;i++)
        {
            if(t[i]+t[i+1]>t[i+2])
            {
                flag=true;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
