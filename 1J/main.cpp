#include <iostream>
#include <stdio.h>
using namespace std;


int su[50]={0};
int res[100],visit[100]={1};
int n;
void dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(visit[i+x]==1&&su[i+x]==1)
        {
            visit[i+x]=0;
            dfs(i+x);
        }
    }
}
int main()
{
    for(int i=2;i<50;i++)
    {
        int flag=1;
        for(int j=2;j*j<i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag) s[i]=1;
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            dfs(i);
        for(int i=n;i>=1;i--)
            printf("%d ",res[i]);
    }
    return 0;
}
