#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[1005];
int s[1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        int p=i;
        while(vis[p]==false)
        {
            vis[p]=true;
            p=s[p];
        }
        printf("%d ",p);
    }
    cout<<endl;
    return 0;
}
