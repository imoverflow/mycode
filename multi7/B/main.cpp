#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_free[505]={true};
bool vis[505]={false};
int main()
{
    for(int i=2;i<=500;i++)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=500;j+=i)
            {
                vis[j]=true;
                is_free[j]=false;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++)
        {
            for(int i=j;j<=n;j++)
            {
                zs
            }
        }
    }
    return 0;
}
