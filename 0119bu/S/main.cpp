#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int val,index;
}s[100005];
bool cmp(const node &a,const node &b)
{
    if(a.val==b.val)
        return a.index<b.index;
    return a.val<b.val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i].val);
        s[i].index=i;
    }
    sort(s,s+n,cmp);
    int nowval=s[0].val;
    int ans=INF;
    for(int i=1;i<n;i++)
    {
        if(nowval==s[i].val)
        {
            ans=min(ans,s[i].index-s[i-1].index);
        }else{
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
