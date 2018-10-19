#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,m;
char s[105][105];
bool vis[105][105];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void bfs1(int a,int b)
{
    queue<pii> q;
    q.push(pii(a,b));
    vis[a][b]=true;
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=0 && xx<=n && yy>=0 && yy<102 && !vis[xx][yy] &&s[xx][yy]=='1')
            {
                q.push(pii(xx,yy));
                vis[xx][yy]=true;
            }
        }
    }
}
void bfs2(int a,int b)
{
    queue<pii> q;
    q.push(pii(a,b));
    vis[a][b]=true;
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=0 && xx<=n && yy>=0 && yy<102 && !vis[xx][yy] && s[xx][yy]=='0')
            {
                q.push(pii(xx,yy));
                vis[xx][yy]=true;
            }
        }
    }
}
int main()
{
//    freopen("a.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        memset(s,0,sizeof s);
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(int j=m;j<103;j++)
            {
                s[i][j]='0';
            }
        }
        for(int i=0;i<103;i++)
        {
            s[n][i]='0';
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<102;j++)
            {
                if(!vis[i][j]&&s[i][j]=='1')
                {
                    cnt1++;
                    bfs1(i,j);
                }
            }
        }
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<102;j++)
            {
                if(!vis[i][j]&&s[i][j]=='0')
                {
                    cnt2++;
                    bfs2(i,j);
                }
            }
        }
        if(cnt1==1&&cnt2==2)
        {
            printf("0\n");
        }else if(cnt2==1&&cnt1==1)
        {
            printf("1\n");
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
