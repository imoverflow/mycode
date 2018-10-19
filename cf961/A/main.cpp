#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int s[1005];
int main()
{
    memset(s,0,sizeof s);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        s[a]++;
    }
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,s[i]);
    }
    cout<<ans<<endl;
    return 0;
}
