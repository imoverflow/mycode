#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double EPS=1e-10;
double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator +(P p)
    {
        return P(add(x,p.x),add(y,p.y));
    }
    P operator -(P p)
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator *(double d)
    {
        return P(x*d,y*d);
    }
    double dot(P p)
    {
        return add(x*p.x,y*p.y);
    }
    double det(P p)
    {
        return add(x*p.y,-y*p.x);
    }
};
void cal(P a,P b,P c)
{
    P d=(b-a)+(c-a)+a;
    printf("%.3f %.3f\n",d.x,d.y);
}
int main()
{
    double a1,a2,b1,b2,c1,c2,d1,d2;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2))
    {
        P A(a1,a2);
        P B(b1,b2);
        P C(c1,c2);
        P D(d1,d2);
        if(fabs((A-B).x)<EPS&&fabs((A-B).y)<EPS)
        {
            cal(A,C,D);
        }else if(fabs((A-C).x)<EPS&&fabs((A-C).y)<EPS)
        {
            cal(A,B,D);
        }else if(fabs((A-D).x)<EPS&&fabs((A-D).y)<EPS)
        {
            cal(A,B,C);
        }else if(fabs((B-C).x)<EPS&&fabs((B-C).y)<EPS)
        {
            cal(B,A,D);
        }else if(fabs((B-D).x)<EPS&&fabs((B-D).y)<EPS)
        {
            cal(B,A,C);
        }else if(fabs((C-D).x)<EPS&&fabs((C-D).y)<EPS)
        {
            cal(C,A,B);
        }
//        printf("%.10f %.10f\n",D.x,D.y);

    }
    return 0;
}
