#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct aa{
    int val,index;
}a[200006];
int b[200006];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
bool cmp1(const aa &a,const aa &b)
{
    return a.val<b.val;
}
bool cmp2(const aa &a,const aa &b)
{
    return a.index<b.index;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].index=i;
    }
    sort(b,b+n,cmp);
    sort(a,a+n,cmp1);
    for(int i=0;i<n;i++)
    {
        a[i].val=b[i];
    }
    sort(a,a+n,cmp2);
    for(int i=0;i<n;i++)
    {
        if(i==0)
            printf("%d",a[i].val);
        else
            printf(" %d",a[i].val);
    }
    return 0;
}
