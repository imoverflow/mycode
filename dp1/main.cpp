#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a,b,res=0;
char s[100][100];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dfs(int x,int y)
{
    s[x][y]='#';
    res++;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx && nx<a && 0<=ny && ny<b && s[nx][ny]=='.') dfs(nx,ny);
    }
    return res;
}

int main()
{
    scanf("%d%d",&b,&a);
    getchar();
    while(a!=0&&b!=0)
    {
        res=0;
        pair <int ,int> p;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                scanf("%c",&s[i][j]);
                if(s[i][j]=='@')
                {
                    p.first=i;
                    p.second=j;
                }
            }
            getchar();
        }
        dfs(p.first,p.second);
        printf("%d\n",res);
        scanf("%d%d",&b,&a);
        getchar();
    }
    return 0;
}
