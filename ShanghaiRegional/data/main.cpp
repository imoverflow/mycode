#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    int t=100000;
    printf("%d\n",t);
    srand(time(0));
    while(t--)
    {
        int cx,cy,r;
        int ax,ay,vx,vy,bx,by;
        cx=cy=r=1;
        ax=(rand()%998+2)*(rand()%2==1?-1:1);
        ay=(rand()%998+2)*(rand()%2==1?-1:1);
        vx=(rand()%998+2)*(rand()%2==1?-1:1);
        vy=(rand()%998+2)*(rand()%2==1?-1:1);
        bx=(rand()%998+2)*(rand()%2==1?-1:1);
        by=(rand()%998+2)*(rand()%2==1?-1:1);
        cout<<cx<<" "<<cy<<" "<<r<<endl;
        cout<<ax<<" "<<ay<<" "<<vx<<" "<<vy<<endl;
        cout<<bx<<" "<<by<<endl;
    }
    return 0;
}
