#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int s[5005];
int p[5005];
int r[5005];
bool visx[5005];
bool visy[5005];
int match[5005];
int lx[5005];
int ly[5005];
int w[5005][5005];
struct node{
    int a,b;
    node(int x,int y):a(x),b(y){};
};
bool cmp(const node &a,const node &b)
{
    return a.a<b.a;
}
bool findpath(int u)
{
    visx[u]=true;
    for(int i=1;i<=m;i++)
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
    for(int i=1;i<=n;i++)
    {
        while(true)
        {
//            cout<<"he"<<endl;
            int d=INF;
            memset(visx,0,sizeof visx);
            memset(visy,0,sizeof visy);
            if(findpath(i)) break;
            else{
                for(int j=1;j<=n;j++)
                {
                    if(visx[j])
                    {
                        for(int k=1;k<=m;k++)
                        {
                            if(!visy[k]&&d>lx[j]+ly[k]-w[j][k])
                                d=lx[j]+ly[k]-w[j][k];
                        }
                    }
                }
                for(int j=1;j<=n;j++)
                    if(visx[j])
                        lx[j]-=d;
                for(int j=1;j<=m;j++)
                    if(visy[j])
                        ly[j]+=d;
            }
        }
    }
    vector<node> v;
    for(int i=1;i<=m;i++)
    {
        if(match[i]!=-1&&w[match[i]][i]!=-INF)
        {
            v.push_back(node(match[i],i));
        }else if(w[match[i]][i]==-INF)
        {
            printf("impossible\n");
            return 0;
        }
    }
    if(v.size()!=n)
    {
        printf("impossible\n");
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",v[i].b);
}
int main()
{
    memset(match,-1,sizeof match);
    memset(lx,0,sizeof lx);
    memset(ly,0,sizeof ly);
    memset(visx,0,sizeof visx);
    memset(visy,0,sizeof visy);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=n;i++)
    {
        int d=-INF;
        for(int j=1;j<=m;j++)
        {
            if(s[i]<=p[j])
            {
                w[i][j]=-r[j];
            }else{
                w[i][j]=-INF;
            }
            d=max(d,w[i][j]);
        }
        lx[i]=d;
    }

    KM();
    return 0;
}
