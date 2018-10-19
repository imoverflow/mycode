#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=-INF;
    for(int i=1;i<n;i++)
    {
        ans=max(ans,min(a/i,b/(n-i)));
    }
    printf("%d",ans);
    return 0;
}
