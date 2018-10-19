#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
char s[105][105];
bool visx[105],visy[105];
int lx[105],ly[105],match[105],w[105][105];
pair<int,int>H[105];
pair<int,int>M[105];
int mcnt,hcnt;
bool findpath(int u)
{
    visx[u]=true;
    for(int i=0;i<hcnt;i++)
    {
        if(!visy[i]&&lx[u]+ly[i]==w[u][i])
        {
            visy[i]=true;
            if(match[i]==-1||findpath(match[i]))
            {
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int KM()
{
    for(int i=0;i<mcnt;i++)
    {
        while(true)
        {
            memset(visx,0,sizeof visx);
            memset(visy,0,sizeof visy);
            if(findpath(i))
                break;
            else{
                int d=INF;
                for(int j=0;j<mcnt;j++)
                {
                    if(visx[j])
                    {
                        for(int k=0;k<hcnt;k++)
                        {
                            if(!visy[k]&&d>lx[j]+ly[k]-w[j][k])
                                d=lx[j]+ly[k]-w[j][k];
                        }
                    }
                }
                for(int j=0;j<mcnt;j++)
                {
                    if(visx[j])
                        lx[j]-=d;
                    if(visy[j])
                        ly[j]+=d;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<hcnt;i++)
    {
        ans+=w[match[i]][i];
    }
    return ans;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        mcnt=0;
        hcnt=0;
        memset(w,0,sizeof w);
        memset(match,-1,sizeof match);
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='m')
                {
                    M[mcnt].first=i;
                    M[mcnt++].second=j;
                }
                if(s[i][j]=='H')
                {
                    H[hcnt].first=i;
                    H[hcnt++].second=j;
                }
            }
        }
        for(int i=0;i<mcnt;i++)
        {
            ly[i]=0;
            lx[i]=-INF;
            for(int j=0;j<hcnt;j++)
            {
                w[i][j]=-(abs(M[i].first-H[j].first)+abs(M[i].second-H[j].second));
                lx[i]=max(lx[i],-(abs(M[i].first-H[j].first)+abs(M[i].second-H[j].second)));
            }
        }
        int p=KM();
        printf("%d\n",-p);
    }
    return 0;
}
