#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
unsigned x, y, z;
P b[105];
unsigned a[10000007];
unsigned ans[10000007];
unsigned rng61()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
int main()
{
    int n,m,aa,bb,cc;
    int cases=1;
    while(~scanf("%d%d%d%d%d",&n,&m,&aa,&bb,&cc))
    {
        x=aa;
        y=bb;
        z=cc;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i].first);
            b[i].second=i;
        }
        for(int i=0;i<n;i++)
        {
            a[i]=rng61();
        }
        sort(b,b+m);
        b[m].first=n;
        for(int i=m-1;i>=0;i--)
        {
            nth_element(a,a+b[i].first,a+b[i+1].first);
            ans[b[i].second]=a[b[i].first];
        }
        printf("Case #%d:",cases++);
        for(int i=0;i<m;i++)
        {
            printf(" %u",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
