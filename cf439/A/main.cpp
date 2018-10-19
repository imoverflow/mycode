#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s1[2005];
int s2[2005];
int vis[2000006]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
        vis[s1[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s2[i]);
        vis[s2[i]]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i^j]==1)
                ans++;
        }
    }
    if(ans%2==0)
        printf("Karen\n");
    else
        printf("Koyomi\n");
    return 0;
}
