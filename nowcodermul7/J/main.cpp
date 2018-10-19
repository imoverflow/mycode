#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[1005][1005];
int len[1005];
int lmin[1005][1005];
int umin[1005][1005];
int pos[400];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",s[i]+1);
    }
    for(int i=1; i<=n; i++)
    {
        memset(pos,0,sizeof pos);
        for(int j=1; j<=m; j++)
        {
            lmin[i][j]=min(lmin[i][j-1]+1,j-pos[s[i][j]]);
            pos[s[i][j]]=j;
        }
    }
    for(int j=1; j<=m; j++)
    {
        memset(pos,0,sizeof(pos));
        for(int i=1; i<=n; i++)
        {
            umin[i][j]=min(umin[i-1][j]+1,i-pos[s[i][j]]);
            pos[s[i][j]]=i;
        }
    }
    long long ans=0;
    for(int j=1; j<=m; j++)
    {
        memset(len,0,sizeof len);
        for(int i=1; i<=n; i++)
        {
            for(int k=0; k<lmin[i][j]; k++)
            {
                len[k]=min(len[k]+1,umin[i][j-k]);
                if(k)
                    len[k]=min(len[k],len[k-1]);
                ans+=len[k];
            }
            for(int k=lmin[i][j];k<=54;k++) len[k]=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
