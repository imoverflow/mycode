#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b;
}s[1000005];
bool cmp(const node &a,const node &b)
{
    return a.a-a.b>b.a-b.b;
}
int main()
{
    int n,m;
    long long sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
        sum+=s[i].a;
    }
    sort(s,s+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(sum<=m)
            break;
        sum=sum-s[i].a+s[i].b;
        cnt++;
    }
    if(sum>m)
    {
        cout<<-1<<endl;
    }else
        cout<<cnt<<endl;
    return 0;
}
