#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int s[1056];
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&s[i]);
    }
    s[n]=INF;
    sort(s,s+n);
    int cnt=INF;
    for(int i=0;i<n;i++)
    {
        int x=upper_bound(s+i,s+n,s[i]+d)-(s+i);
        cnt=min(cnt,n-x);
    }
    printf("%d\n",cnt);
    return 0;
}
