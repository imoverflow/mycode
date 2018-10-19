#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[105*105];
int ans[105][105];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n*m;i++)
        {
            scanf("%d",&s[i]);
        }
        int p=m*n;
        int v=n,u=m;
        int c=0,r=0;
        int rr=m,ll=0,uu=0,dd=n;
        for(int i=0;i<p;)
        {
            if(c==ll&&r==uu)
            {
                for(int j=ll;j<rr;j++)
                {
                    ans[r][j]=s[i];
                    i++;
                }
                c=rr-1;
                r=uu;
            }
            uu++;
            if(c==rr-1&&r==uu-1)
            {
                for(int j=uu;j<dd;j++)
                {
                    ans[j][c]=s[i];
                    i++;
                }
                r=dd-1;
                c=rr-1;
            }
            rr--;
            if(c==rr&&r==dd-1&&dd-uu>0)
            {
                for(int j=rr-1;j>=ll;j--)
                {
                    ans[r][j]=s[i];
                    i++;
                }
                c=ll;
                r=dd-1;
            }
            dd--;
            if(c==ll&&r==dd&&rr-ll>0)
            {
                for(int j=dd-1;j>=uu;j--)
                {
                    ans[j][c]=s[i];
                    i++;
                }
                c=ll+1;
                r=uu;
            }
            ll++;
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<u;j++)
            {
                if(j==0)
                    printf("%d",ans[i][j]);
                else
                    printf(" %d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
