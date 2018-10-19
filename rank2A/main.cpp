#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int s1[200005];
int s2[200005]={0};
int vis[360005];

int check(int x)
{
    memset(vis,0,sizeof(vis));
    for(int j=0;j<n;j++)
    {
        if(s2[(s1[j]+x)%360000]>0&&vis[(s1[j]+x)%360000]<=s2[(s1[j]+x)%360000])
        {
            vis[(s1[j]+i)%360000]++;
            flag=1;
            continue;
        }else
        {
            flag=0;
            break;
        }
    }
}
int main()
{
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s2[a]++;
    }
    int flag=0;
    for(int i=0;i<360000;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=0;j<n;j++)
        {
            if(s2[(s1[j]+i)%360000]>0&&vis[(s1[j]+i)%360000]<=s2[(s1[j]+i)%360000])
            {
                vis[(s1[j]+i)%360000]++;
                flag=1;
                continue;
            }else
            {
                flag=0;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        printf("possible\n");
    else
        printf("impossible\n");
    return 0;
}
