#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;


struct enter{
    int first,last;
}s[30];
struct ti{
    int l,r;
}tim[30];
bool cmp(const enter&a,const enter&b)
{
    if(a.first==b.first)
        return a.last<b.last;
    else
        return a.first<b.first;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    memset(s,0,sizeof s);
    memset(tim,0,sizeof tim);
    for(int i=1;i<=n;i++)
    {
        char t;
        scanf("%c",&t);
        if(s[t-'A'].first==0)
        {
            s[t-'A'].first=i;
            s[t-'A'].last=i;
        }else{
            s[t-'A'].last=i;
        }
    }
    sort(s,s+26,cmp);
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;;j++)
        {
            if(tim[j].l==0&&tim[j].r==0)
            {
                tim[j].l=s[i].first;
                tim[j].r=s[i].last;
                cnt=max(cnt,j);
                break;
            }else
            {
                if(tim[j].l>=s[i].last||tim[j].r<=s[i].first)
                {
                    tim[j].l=min(s[i].first,tim[j].l);
                    tim[j].r=max(s[i].last,tim[j].r);
                    cnt=max(cnt,j);
                    break;
                }
            }
        }
    }
    if(cnt<k)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
