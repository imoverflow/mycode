#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int st[10005]={0},v[10005],s[105],a[10005],sum;
int dp[10005];
int abs(int a)
{
    if(a>0) return a;
    else return -a;
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        memset(st,0,sizeof(st));
        memset(v,0,sizeof(v));
        sum=0;
        int m=0;
        int cou=0;
        for(int i=0;i<t;i++)
        {
            scanf("%d",&s[i]);
            sum+=s[i];
            v[s[i]]=1;
            st[cou++]=s[i];
        }
        int q=cou;
        for(int i=0;i<t;i++)
        {
            for(int j=i+1;j<t;j++)
            {
                v[s[i]+s[j]]=1;
                st[cou++]=s[i]+s[j];
                for(int k=0;k<cou-1;k++)
                {
                    if(k==i||k==j) continue;
                    v[abs(st[k]-st[cou-1])]=1;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<sum;i++)
        {
            if(v[i]==0)
            {
                a[cnt++]=i;
                m=1;
            }
        }
        if(m==0)
            printf("0\n");
        else
        {
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++)
            {
                printf("%d%c",a[i],i<cnt-1?' ':'\n');
            }
        }
    }
    return 0;
}
