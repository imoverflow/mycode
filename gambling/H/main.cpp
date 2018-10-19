#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 10010
using namespace std;

int lim[105];
int sg[MAX];
void getsg(int num)
{
    bool s[MAX];
    memset(sg,0,sizeof sg);
    for(int i=0;i<MAX;i++)
    {
        memset(s,0,sizeof s);
        for(int j=0;j<num;j++)
        {
            if(i-lim[j]>=0)
                s[sg[i-lim[j]]]=1;
        }
        for(int j=0;j<MAX;j++)
        {
            if(s[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&lim[i]);
        }
        getsg(n);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int k,ans=0;
            scanf("%d",&k);
            for(int i=0;i<k;i++)
            {
                int a;
                scanf("%d",&a);
                ans=ans^sg[a];
            }
            if(ans)
                printf("W");
            else
                printf("L");
        }
        printf("\n");
    }
    return 0;
}
