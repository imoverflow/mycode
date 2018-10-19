#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
bool visx[205],visy[205];
int w[205][205],lx[205],ly[205],match[205];
bool hungary(int x)
{
    visx[x]=true;
    for(int i=1;i<=n;i++)
    {
        if(!visy[i]&&lx[x]+ly[i]==w[x][i])
        {
            visy[i]=true;
            if(match[i]==-1||hungary(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}
int km()
{
    for(int i=1;i<=n;i++)
    {
        while(true)
        {
            memset(visx,0,sizeof visx);
            memset(visy,0,sizeof visy);
            if(hungary(i))
                break;
            else
            {
                int delta=1<<30;
                for(int j=1;j<=n;j++)
                {
                    if(visx[j])
                    {
                        for(int k=1;k<=n;k++)
                        {
                            if(!visy[k]&&delta>lx[j]+ly[k]-w[j][k])
                            {
                                delta=lx[j]+ly[k]-w[j][k];
                            }
                        }
                    }
                }
//                if(delta==INF) return -1;
                for(int j=1;j<=n;j++)
                {
                    if(visx[j])
                        lx[j]-=delta;
                    if(visy[j])
                        ly[j]+=delta;
                }
            }
//            cout<<"sd "<<endl;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(w[match[i]][i]==-INF) return -1;
        ans+=w[match[i]][i];
    }
    return -ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(match,-1,sizeof match);
//        memset(w,0,sizeof w);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                w[i][j]=-INF;
            }
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(w[a][b]<-c)
                w[a][b]=-c;
//            w[a][b]=max(-c,w[a][b]);
        }
        for(int i=1;i<=n;i++)
        {
            ly[i]=0;
            lx[i]=-INF;
            for(int j=1;j<=n;j++)
            {
                if(lx[i]<w[i][j])
                    lx[i]=w[i][j];
//                lx[i]=max(lx[i],w[i][j]);
            }
        }
        int p=km();
        printf("%d\n",p);
    }
    return 0;
}
