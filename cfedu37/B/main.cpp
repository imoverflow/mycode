#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
    int index;
}s[1005];
bool cmp(const node &a,const node &b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    return a.index<b.index;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&s[i].l,&s[i].r);
            s[i].index=i;
        }
        sort(s,s+n,cmp);
        int now=1;
        for(int i=0;i<n;i++)
        {
            if(s[i].r>=now)
            {
                printf("%d%c",max(now,s[i].l),i==n-1?'\n':' ');
                now=max(now,s[i].l)+1;
            }else{
                printf("0%c",i==n-1?'\n':' ');
            }
        }
    }
    return 0;
}
