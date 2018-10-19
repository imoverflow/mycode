#include <iostream>
#include <stdio.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const long long INF=1e18;
bool cmp(const long long &a,const long long &b)
{
    return (a%INF)<(b%INF);
}
long long s[1000006];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&s[i]);
        }
        for(int i=0;i<k;i++)
        {
            int a;
            scanf("%d",&a);
            s[a]+=INF;
        }
        sort(s+1,s+n+1,cmp);
        int ans=0;
        for(int i=0;i<k;i++)
        {
            int a;
            scanf("%d",&a);
            if(s[a]!=s[a]%INF)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
