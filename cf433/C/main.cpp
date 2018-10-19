#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    long long cost,init,st;
}s[300005];
set<long long>ss;
bool cmp1(const node &a,const node &b)
{
    return a.cost>b.cost;
}
bool cmp2(const node &a,const node &b)
{
    return a.init<b.init;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&s[i].cost);
        s[i].init=i+1;
    }
    sort(s,s+n,cmp1);
    int p=k+1;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i].init>=p)
        {
            if(ss.find(s[i].init)==ss.end())
            {
                ss.insert(s[i].init);
                s[i].st=s[i].init;
            }else{
                int x=s[i].init+1;
                while(ss.find(x)!=ss.end())
                {
                    x++;
                }
                ss.insert(x);
                s[i].st=x;
                ans+=(x-s[i].init)*s[i].cost;
            }
        }else{
            while(ss.find(p)!=ss.end())
            {
                p++;
            }
            ss.insert(p);
            ans+=(p-s[i].init)*s[i].cost;
            s[i].st=p;
        }
    }
    sort(s,s+n,cmp2);
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++)
    {
        if(i==0)
            printf("%I64d",s[i].st);
        else
            printf(" %I64d",s[i].st);
    }
    return 0;
}
