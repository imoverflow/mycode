#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[1005][20];
int x[1005];
int tt[1005];
int dp[1005][1<<11];
int n,m,k;
bool check(int y)
{
    memset(tt,0,sizeof tt);
    map<int,int>mm;
    for(int j=0;j<n;j++)
    {
        tt[j]+=(x[j]&y);
        mm[tt[j]]++;
    }
    int res=0;
    for(auto i:mm)
    {
        res+=(n-i.second)*i.second;
    }
    res/=2;
//    cout<<res<<endl;
    return res>=k;
}
int main()
{
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        memset(x,0,sizeof x);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                x[i]=x[i]*2+(s[i][j]=='A');
            }
        }
        int ans=0;
        for(int i=1,j=(1<<m);i<j;i++)
        {
            if(check(i))
                ans++;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
