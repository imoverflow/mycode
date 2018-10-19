#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
struct node{
    int sc,cost;
    int index;
}s[200005];
int n,T;
bool cmp(const node &a,const node &b)
{
    if(a.cost!=b.cost)
        return a.cost<b.cost;
    else
        return a.sc<b.sc;
}
bool cmp1(const node &a,const node &b)
{
    if(a.sc!=b.sc)
        return a.sc<b.sc;
    else
        return a.cost<b.cost;
}
bool check(int x,vector<int>&g)
{
    int time=0;
    g.clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i].sc>=x)
        {
            cnt++;
            time+=s[i].cost;
            g.push_back(i);
        }
        if(cnt==x)
            break;
    }
    if(time<=T&&cnt==x)
    {
        return true;
    }else{
        return false;
    }
}

int main()
{

    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s[i].index=i;
        s[i].cost=b;
        s[i].sc=a;
    }
    sort(s+1,s+n+1,cmp);
    int ansl=-1,ansr=-1;
    int ll,rr;
    int l=0,r=n+1;
    vector<int>ans;
    vector<int>g;
    while(l+1<r)
    {
        int mid=(l+r)>>1;
        if(check(mid,g))
        {
            l=mid;
            ans.clear();
            for(int i=0;i<g.size();i++)
            {
                ans.push_back(g[i]);
            }
        }else{
            r=mid;
        }
    }
    if(ans.size()==0)
    {
        printf("0\n0\n");
    }else{
        printf("%d\n",ans.size());
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            if(i==0)
                printf("%d",s[ans[i]].index);
            else
                printf(" %d",s[ans[i]].index);
        }
        printf("\n");
    }
    return 0;
}
