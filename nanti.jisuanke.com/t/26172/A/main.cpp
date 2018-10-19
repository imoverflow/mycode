#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

long long mp[1000][1000];
long long v[2000];
bool vis[2000];
long long dis[2000];

long long Stoer_Wagner(long long n)
{
    long long res=INF;
    for(int i=0;i<n;i++)
    {
        v[i]=i;
    }
    while(n>1)
    {
        long long k=1,pre=0;
        for(int i=1;i<n;i++)
        {
            dis[v[i]]=mp[v[0]][v[i]];
            if(dis[v[i]]>dis[v[k]])
            {
                k=i;
            }
        }
        memset(vis,0,sizeof vis);
        vis[v[0]]=true;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)
            {
                res=min(res,dis[v[k]]==0?INF:dis[v[k]]);
                for(int j=0;j<n;j++)
                {
                    mp[v[pre]][v[j]]+=mp[v[j]][v[k]];
                    mp[v[j]][v[pre]]+=mp[v[j]][v[k]];
                }
                v[k]=v[--n];
            }
            vis[v[k]]=true;
            pre=k;
            k=-1;
            for(int j=1;j<n;j++)
            {
                if(!vis[v[j]])
                {
                    dis[v[j]]+=mp[v[pre]][v[j]];
                    if(k==-1||dis[v[k]]<dis[v[j]])
                    {
                        k=j;
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(mp,0,sizeof mp);
        memset(dis,0,sizeof dis);
        long long res=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            res+=a;
            mp[0][i]=a;
        }
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a);
            mp[n+i][n+m+1]=a;
        }
        for(int i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            for(int j=0;j<a;j++)
            {
                int x;
                scanf("%d",&x);
                mp[i][n+x]=INF;
            }
            for(int j=0;j<b;j++)
            {
                int x;
                scanf("%d",&x);
                mp[i][x]=INF;
            }
        }
//        for(int i=0;i<10;i++)
//        {
//            for(int j=0;j<10;j++)
//            {
//                printf("%10lld ",mp[i][j]);
//            }
//            printf("\n");
//        }
//        cout<<Stoer_Wagner(n+m+2)<<endl;
        res-=Stoer_Wagner(n+m+2);
        printf("%lld\n",res);
    }
    return 0;
}
