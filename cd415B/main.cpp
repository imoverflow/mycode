#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct node{
    long long pro,cus;
}s[100005];

bool cmp(const struct node &a,const struct node &b)
{
//    if(min(a.pro*2,a.cus)==min(b.pro*2,b.cus))
//    {
//        return min(a.pro,a.cus)>min(b.pro,b.cus);
//    }
    return min(a.pro*2,a.cus)-min(a.pro,a.cus)>min(b.pro*2,b.cus)-min(b.pro,b.cus);
}
int main()
{
    int n,f;
    cin>>n>>f;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&s[i].pro,&s[i].cus);
    }
    sort(s,s+n,cmp);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(i<f)
            sum+=min(s[i].pro*2,s[i].cus);
        else
            sum+=min(s[i].cus,s[i].pro);
    }
    printf("%lld\n",sum);
    return 0;
}
