#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct AA{
    int l,r;
}s[200005];
bool cmp(const AA &a,const AA &b)
{
    if(a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].l,&s[i].r);
    }
    sort(s,s+n,cmp);
    int flag=1;
    int r1=-1,r2=-1;
    for(int i=0;i<n;i++)
    {
        if(r1<s[i].l)
            r1=s[i].r;
        else if(r2<s[i].l)
            r2=s[i].r;
        else{
            flag=0;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
