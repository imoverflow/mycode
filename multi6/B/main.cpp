#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int s[100005];

long long solve(int l,int r)
{
    long long ans=0;
    for(int i=l;i<=r;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            int p=__gcd(s[i],s[j]);
            if(a[p]>j&&a[p]<=r) ans+=p;
        }
    }
    return ans;
}
int n,m;
//long long ans[100005];
//void solve()
//{
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=s[i];j++)
//        {
//            if(s[i]%j==0)
//            {
//                if(i<a[j])
//                    ans[i]+=j;
//            }
//        }
//    }
//}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
//        memset(ans,0,sizeof ans);
        memset(a,0,sizeof a);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            a[s[i]]=i;
        }
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",ans[l]-ans[r]);
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=i+1;j<=n;j++)
//            {
//                printf("i=%d j=%d %lld\n",i,j,solve(i,j));
//            }
//        }
    }
    return 0;
}
