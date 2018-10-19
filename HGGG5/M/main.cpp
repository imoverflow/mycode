#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sx,sy,ex,ey;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    if(sx>ex&&sy<ey)
    {
        printf("%d\n",2*(abs(ex-1-sx)+abs(ey+1-sy)));
    }else if(ex>sx&&ey>sy)
    {
        printf("%d\n",2*(abs(ex+1-sx)+abs(ey+1-sy)));
    }else if(ex>sx&&sy>ey)
    {
        printf("%d\n",2*(abs(ex+1-sx)+abs(ey-1-sy)));
    }else if(sx>ex&&sy>ey)
    {
        printf("%d\n",2*(abs(ex-1-sx)+abs(ey-1-sy)));
    }else if(sx==ex)
    {
        printf("%d\n",4+2*(abs(ey-sy)+1));
    }else if(sy==ey)
    {
        printf("%d\n",4+2*(abs(sx-ex)+1));
    }
    return 0;
}
