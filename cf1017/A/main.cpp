#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c,d,id;
}s[10005];
bool cmp(const node &a,const node &b)
{
    if(a.a+a.b+a.c+a.d!=b.a+b.b+b.c+b.d) return a.a+a.b+a.c+a.d>b.a+b.b+b.c+b.d;
    return a.id<b.id;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
        s[i].id=i;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(s[i].id==0)
        {
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}
