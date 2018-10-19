#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[200005];
int vis[200005];
int ans[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        vis[s[i]]++;
    }
    for(int i=0,k=1;i<n;i++)
    {
        if(vis[s[i]]>1&&s[i]>k)
        {
            while(vis[k]!=0)
            {
                k++;
            }
            vis[s[i]]--;
            vis[k]=1;
            ans[i]=k;
            while(vis[k]!=0)
            {
                k++;
            }
        }else{
            ans[i]=s[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
            printf("%d",ans[i]);
        else
            printf(" %d",ans[i]);
    }
    return 0;
}
