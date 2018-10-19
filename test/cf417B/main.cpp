#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char s[20][110];
int n,m;
int ans=0;
int dfs(int k,int lr)  //lr==0=l  lr==1==r
{

    int p=strlen(s[k]);
    int l=0,r=0;
    for(int i=0;i<p;i++)
    {
        if(s[k][i]=='1')
        {
            if(l==0) l=i,r=i;
            else r=i;
        }
    }
    if(k==n-1)
    {
        if(l==0&&r==0)
        {
            if(lr==0)
            {
                int flag=0;
                for(int i=n-2;i>=0;i--)
                {
                    for(int j=0;j<m+2;j++)
                    {
                        if(s[i][j]=='1')
                        {
                            return -(n-1-i+j);
                            flag=1;
                            goto label1;
                        }
                    }
                }
                label1:
                if(flag==0)
                    return -(n-1);
            }else{
                int flag=0;
                for(int i=n-2;i>=0;i--)
                {
                    for(int j=m+1;j>=0;j--)
                    {
                        if(s[i][j]=='1')
                        {
                            return -(n-1-i+m+1-j);
                            goto label2;
                        }
                    }
                }
                label2:
                if(flag==0)
                    return -(n-1);
            }
        }else{
            if(lr==0)
            {
                return r;
            }else{
                return m+1-l;
            }
        }
    }else{
        if(lr==0)
        {
            return min(dfs(k+1,1)+m+2,dfs(k+1,0)+2*r+1);
        }else{
            if(l!=0)
                return min(dfs(k+1,0)+m+2,dfs(k+1,1)+(m+2-l)*2-1);
            else
                return dfs(k+1,1)+1;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[n-1-i]);
    }
    printf("%d\n",dfs(0,0));
    return 0;
}
