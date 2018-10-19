#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>       //be care of the pow
using namespace std;
int x1,x2;
int s[20][1000]={0};
int coun=0;
void dihui(int x,int y)
{
    if(s[x][y]==2)
        coun++;
    if(s[x][y+1]==0&&y+1<20)
        dihui(x,y+1);
    else if(s[x+1][y]==0)
        dihui(x+1,y);
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int j=y1+1;j<1000;j++)
        {
            for(int k=0;k<20;k++)
            {
                s[k][j]=1;
            }
        }
        if(y2-1>=0&&x2-2>=0)
            s[y2-1][x2-2]=1;
        if(y2-2>=0&&x2-1>=0)
            s[y2-2][x2-1]=1;
        if(y2-2>=0&&x2+1>=0)
            s[y2-2][x2+1]=1;
        if(y2-1>=0&&x2+2>=0)
            s[y2-1][x2+2]=1;
        if(y2+1<20&&x2+2>=0)
            s[y2+1][x2+2]=1;
        if(y2+2<20&&x2+1>=0)
            s[y2+2][x2+1]=1;
        if(y2+2<20&&x2-1>=0)
            s[x2+2][x2-1]=1;
        if(y2+1<20&&x2-2>=0)
            s[y2+1][x2-2]=1;
        s[y2][x2]=1;
        s[y1][x1]=2;
        dihui(0,0);
        printf("%d\n",coun);
    }
    return 0;
}
