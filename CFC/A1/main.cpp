#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s1[5000];
int s2[5000];
int vis[5000000];
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
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[s1[i]^s2[j]]==1)
            {
                cnt++;
            }
        }
    }
    if(cnt%2==0)
    {
        printf("Karen\n");
    }else{
        printf("Koyomi\n");
    }
    return 0;
}
