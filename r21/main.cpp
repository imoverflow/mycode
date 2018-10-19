#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int ,int> P;
const int INF=100000000;
char s[1005][1005];
int Y[1005][1005],v[1005][1005]={0};
int ysx,ysy,msx,msy,we,he;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int bfs(int st,int en)
{
    int num=0;
    queue<P> que;
    memset(Y,0,sizeof(Y));
    que.push(P(st,en));
    Y[st][en]=1;
    do
    {
        P p=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx && nx<he && 0<=ny && ny<we &&s[nx][ny]=='*')
            {
                num++;
            }
            if(0<=nx && nx<he && 0<=ny && ny<we && s[nx][ny]!='*'&&Y[nx][ny]==0)
            {
                que.push(P(nx,ny));
                Y[nx][ny]=1;
            }
        }
    }while(que.size());
    printf("%d\n",num);
    return num;
}
int main()
{
    int k,a[100000],b[100000];
    scanf("%d %d %d",&he,&we,&k);
        getchar();
        for(int i=0;i<he;i++)
        {
            for(int j=0;j<we;j++)
            {
                scanf("%c",&s[i][j]);
            }
            getchar();
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=0;i<k;i++)
        {
            if(v[a[i]][b[i]]==0)
            v[a[i]][b[i]]=bfs(a[i]-1,b[i]-1);
            else
                printf("%d\n",v[a[i]][b[i]]);
        }

    return 0;
}
