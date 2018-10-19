#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int ,int> P;
const int INF=100000000;
char s[300][300];
int v[300]={0},Y[300][300],kfc[300][2];
int ysx,ysy,msx,msy,we,he;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs1()
{
    queue<P> que;
    for(int i=0;i<we;i++)
        for(int j=0;j<he;j++) Y[i][j]=INF;
    que.push(P(ysx,ysy));
    Y[ysx][ysy]=0;
    while(que.size())
    {
        P p=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx && nx<we && 0<=ny && ny<he && s[nx][ny]!='#'&&Y[nx][ny]==INF)
            {
                que.push(P(nx,ny));
                Y[nx][ny]=Y[p.first][p.second]+1;
            }
        }
    }
}
void bfs2()
{
    queue<P> que;
    que.push(P(msx,msy));
    while(que.size())
    {
        P p=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx && nx<we && 0<=ny && ny<he && s[nx][ny]!='#'&&Y[nx][ny]!=INF)
            {
                que.push(P(nx,ny));
                Y[nx][ny]=Y[p.first][p.second]+1;
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&we,&he)!=EOF)
    {
        int nkfc=0;
        getchar();
        for(int i=0;i<we;i++)
        {
            for(int j=0;j<he;j++)
            {
                scanf("%c",&s[i][j]);
                if(s[i][j]=='@')
                {
                    kfc[nkfc][0]=i;
                    kfc[nkfc][1]=j;
                    nkfc++;
                }

                if(s[i][j]=='Y')
                {
                    ysx=i;
                    ysy=j;
                }
                if(s[i][j]=='M')
                {
                    msx=i;
                    msy=j;
                }
            }
            getchar();
        }
        bfs1();
        bfs2();
        for(int i=0;i<nkfc;i++)
        {
            v[i]=Y[kfc[i][0]][kfc[i][1]];
        }
        sort(v,v+nkfc);
        printf("%d\n",v[0]*11);
    }

    return 0;
}
