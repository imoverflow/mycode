#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[500];
int vis[500];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        vis[s[i]]=1;
    }
    sort(s,s+n);
    int cnt=0;
    if(vis[k]==1)
        cnt++;
    for(int i=0;i<k;i++)
    {
        if(vis[i]==0)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
