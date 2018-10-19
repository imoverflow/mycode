#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct wheel{
    int x,y,r;
}s[1005];
bool used[1005];
int n;
bool adj(int x1,int y1,int r1,int x2,int y2,int r2)
{
    return fabs(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))-(r1+r2))<1e-6;
}
struct spe{
    long long pre1,pre2,predir,prer,nowr,index;
};
pair<long long,pair<long long,long long> >ans[2000];
void bfs()
{
    queue<spe>q;
    spe sp;
    sp.pre1=1;
    sp.pre2=1;
    sp.predir=1;
    sp.prer=s[0].r;
    sp.nowr=s[0].r;
    sp.index=0;
    q.push(sp);
    used[0]=true;
    while(!q.empty())
    {
        spe pi;
        pi=q.front();
        q.pop();
        if(pi.predir==1)
            ans[pi.index].first=0;
        else
            ans[pi.index].first=1;
        ans[pi.index].second.first=pi.pre1*pi.prer/__gcd(pi.pre1*pi.prer,pi.pre2*pi.nowr);
        ans[pi.index].second.second=pi.pre2*pi.nowr/__gcd(pi.pre1*pi.prer,pi.pre2*pi.nowr);
        for(int i=0;i<n;i++)
        {
            if(used[i]==false&&adj(s[pi.index].x,s[pi.index].y,s[pi.index].r,s[i].x,s[i].y,s[i].r))
            {
                spe k;
                k.index=i;
                k.nowr=s[i].r;
                k.pre1=ans[pi.index].second.first;
                k.pre2=ans[pi.index].second.second;
                k.predir=ans[pi.index].first;
                k.prer=pi.nowr;
                q.push(k);
                used[i]=true;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        memset(used,0,sizeof used);
        memset(s,0,sizeof s);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].r);
        }
        bfs();                                  //dir 0 shun 1 ni  ; ri
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("1 clockwise\n");
            else if(ans[i].second.first==0&&ans[i].second.second==0){
                printf("not moving\n");
            }else{
                if(ans[i].second.first%ans[i].second.second==0)
                    printf("%lld ",ans[i].second.first/ans[i].second.second);
                else
                    printf("%lld/%lld ",ans[i].second.first/__gcd(ans[i].second.first,ans[i].second.second),ans[i].second.second/__gcd(ans[i].second.first,ans[i].second.second));
                if(ans[i].first==0)
                    printf("clockwise\n");
                else
                    printf("counterclockwise\n");
            }
        }
    }
    return 0;
}
