#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long dis(long long a,long long b,long long c,long long d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
double add(double a,double b)
{
    if(abs(a+b)<1e-10*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P{
    double x,y;
    p(){}
    P(double x,double y):x(x),y(y){}
    P operator -(P p){
        return P(add(x,-p.x),add(y,-p.y));
    }
    double dot(P p){
        return add(x*p.x,y*p.y);
    }
    double det(P p){
        return add(x*p.y,-y*p.x);
    }
};
bool ison(double a,double b,double c,double d,double e,double f)
{
//    double z=((c-a)*(e-a)+(d-b)*(f-b))/(dis(a,b,c,d)*dis(a,b,e,f));
//    if(fabs(fabs(z)-1)<1e-15)
//        return true;
//    else
//        return false;
    P p1(a,b);
    P p2(e,f);
    P q(c,d);
//    P p1,p2,q;
//    p1.x=a;
//    p1.y=b;
//    p2.x=e;
//    p2.y=f;
//    q.x=c;
//    q.y=d;
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}
int main()
{
    int x1,x2,x3,y1,y2,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(dis(x1,y1,x2,y2)-dis(x2,y2,x3,y3)==0&&!ison(x1,y1,x2,y2,x3,y3))
    {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
-1000000000 0 0 1 1000000000 0
*/
