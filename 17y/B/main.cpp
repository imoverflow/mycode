#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;
};
typedef struct Point point;

int multi(point p0, point p1, point p2)
{
    return ( p1.x - p0.x )*( p2.y - p0.y )-( p2.x - p0.x )*( p1.y - p0.y );
}
bool isIntersected(point s1,point e1, point s2,point e2)
{
    return  (max(s1.x,e1.x) >= min(s2.x,e2.x))&&
    (max(s2.x,e2.x) >= min(s1.x,e1.x))
    &&(max(s1.y,e1.y) >= min(s2.y,e2.y))
    &&(max(s2.y,e2.y) >= min(s1.y,e1.y))
    &&(multi(s1,s2,e1)*multi(s1,e1,e2)>0)
    &&(multi(s2,s1,e2)*multi(s2,e2,e1)>0);
}
int main()
{
//    freopen("out","w",stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    point p1,p2,p3,p4;
    while(~scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4))
    {
        p1.x=x1,p1.y=y1;
        p2.x=x2,p2.y=y2;
        p3.x=x3,p3.y=y3;
        p4.x=x4,p4.y=y4;
        if(isIntersected(p1,p2,p3,p4))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
