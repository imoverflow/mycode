#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int s[100005];
int pre[100005];
int next[100005];
int main()
{
    freopen("earthworm.in","r",stdin);
    freopen("earthworm.out","w",stdout);
    int n,m,q,u,v,t;
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    double k=(double)u/v;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int x=1;
    sort(s,s+n);
    int cnt=0;
    while(x<=m)
    {
        int p=s[n+x-2];
        if(x%t==0)
            pre[cnt++]=s[x+n-2];
        s[n+x-1]=p*k+0.00001;
        s[n+x]=p-(int)(p*k+0.00001);
        for(int i=0;i<n+x-1;i++)
        {
            s[i]+=q;
        }
        x++;
        sort(s,s+n+x);
    }
    for(int i=0;i<cnt;i++)
    {
        if(i==0)
            printf("%d",pre[i]);
        else
            printf(" %d",pre[i]);
    }
    printf("\n");
    int flag=0;
    for(int i=n+x-2;i>=0;i--)
    {
        if(flag==0)
        {
            if(i%t==0)
            {
                printf("%d",s[i]);
                flag=1;
            }
        }else{
            if(i%t==0)
            {
                printf(" %d",s[i]);
            }
        }
    }

    return 0;
}
