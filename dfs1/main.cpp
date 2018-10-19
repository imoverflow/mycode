#include <iostream>
#include <stdio.h>
using namespace std;


int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dfs(int x,int y)
{
    if(0<=x+1 && x+1<5 && 0<=y && y<5 && dfs(x+1,y)) return 1;
    if(0<=x-1 && x-1<5 && 0<=y && y<5 && dfs(x-1,y)) return 1;
    if(0<=x && x<5 && 0<=y+1 && y+1<5 && dfs(x,y+1)) return 1;
    if(0<=x && x<5 && 0<=y-1 && y-1<5 && dfs(x,y-1)) return 1;
    printf("(%d,%d)\n",x,y);
}
int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    dfs(0,0);
    return 0;
}
