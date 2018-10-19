#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char s1[100][2000];
char s2[2000][100];
int d1[100][2000];
int d2[2000][100];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m;
pair<int ,int>num1;
pair<int ,int>num2;
int bfs1()              //n<100
{
    queue<pair<int ,int> > que;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            d1[i][j]=INF;
        }
    }
    que.push(num1);
    d1[num1.first][num1.second]=0;
    while(que.size())
    {
        pair<int ,int>p;
        p=que.front();
        que.pop();
        if(p.first==num2.first&&p.second==num2.second)
            break;
        for(int i=0;i<4;i++)
        {
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&s1[nx][ny]=='.'&&d1[nx][ny]==INF)
            {
                pair<int ,int>k;
                k.first=nx;
                k.second=ny;
                que.push(k);
                d1[nx][ny]=d1[p.first][p.second]+1;
            }
        }
    }
    return d1[num2.first][num2.second];
}
int bfs2()
{
    queue<pair<int ,int> > que;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            d2[i][j]=INF;
        }
    }
    que.push(num1);
    d2[num1.first][num1.second]=0;
    while(que.size())
    {
        pair<int ,int>p;
        p=que.front();
        que.pop();
        if(p.first==num2.first&&p.second==num2.second)
            break;
        for(int i=0;i<4;i++)
        {
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&s2[nx][ny]=='.'&&d2[nx][ny]==INF)
            {
                pair<int ,int>k;
                k.first=nx;
                k.second=ny;
                que.push(k);
                d1[nx][ny]=d1[p.first][p.second]+1;
            }
        }
    }
    return d2[num2.first][num2.second];
}
bool check1()
{
    int ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<m;j++)
        {
            if(d1[i][j]!=INF)
                 ans++;
        }
    }
    return ans;
}
bool check2()
{
    int ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<m;j++)
        {
            if(d2[i][j]!=INF)
                 ans++;
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    if(n<100)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&s1[i][j]);
                if(s1[i][j]=='1')
                {
                    num1.first=i;
                    num1.second=j;
                }
                if(s1[i][j]=='2')
                {
                    num2.first=i;
                    num2.second=j;
                }
            }
            getchar();
        }
        if(bfs1()<check1())
        printf("Yes\n");
    else
        printf("No\n");
    }else{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&s2[i][j]);
                if(s1[i][j]=='1')
                {
                    num1.first=i;
                    num1.second=j;
                }
                if(s1[i][j]=='2')
                {
                    num2.first=i;
                    num2.second=j;
                }
            }
            getchar();
        }
        if(bfs2()<check2())
        printf("Yes\n");
    else
        printf("No\n");
    }

    return 0;
}
