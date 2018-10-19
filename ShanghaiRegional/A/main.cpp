#include <iostream>
#include <bits/stdc++.h>
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;

double EPS =1e-10,eps=1e-8;
double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b)))
        return 0;
    return a+b;
}
struct point
{
    double x,y;
    point() {}
    point(double x,double y):x(x),y(y) {}
    point operator + (point p)
    {
        return point(add(x,p.x),add(y,p.y));
    }
    point operator - (point p)
    {
        return point(add(x,-p.x),add(y,-p.y));
    }
    point operator *(double d)
    {
        return point(x*d,y*d);
    }
    point operator / (double a)
    {
        return point (x/a, y/a);
    }
    double dot(point p)
    {
        return add(x*p.x,y*p.y);
    }
    double det(point p)
    {
        return add(x*p.y,-y*p.x);
    }
};
struct line
{
    point a,b;
    line() {}
    line(point a,point b):a(a),b(b) {};
};
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double disptoline(point p,point l1,point l2)
{
    return fabs(xmult(p,l1,l2))/dis(l1,l2);
}
int intersect_seg_circle(point c,double r, point l1,point l2)
{
    double t1=dis(c,l1)-r,t2=dis(c,l2)-r;
    point t=c;
    if (t1<eps||t2<eps)
        return (t1>-eps)+(t2>-eps);
    t.x+=l1.y-l2.y;
    t.y+=l2.x-l1.x;
    return xmult(l1,c,t)*xmult(l2,c,t)<eps&&disptoline(c,l1,l2)-r<eps;
}

int dot_online_in(point p,line l)
{
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
point intersection(point u1,point u2,point v1,point v2)
{
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}
point ptoline(point p,point l1,point l2)
{
    point t=p;
    t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
    return intersection(p,t,l1,l2);
}
void intersection_line_circle(point c,double r,point l1,point l2,point& p1,point& p2)
{
    point p=c;
    double t;
    p.x+=l1.y-l2.y;
    p.y+=l2.x-l1.x;
    p=intersection(p,c,l1,l2);
    t=sqrt(r*r-dis(p,c)*dis(p,c))/dis(l1,l2);
    p1.x=p.x+(l2.x-l1.x)*t;
    p1.y=p.y+(l2.y-l1.y)*t;
    p2.x=p.x-(l2.x-l1.x)*t;
    p2.y=p.y-(l2.y-l1.y)*t;
}
point projection (point p, line a)
{
//    return a.a + (((a.b-a.a) * dot (a.e-a.s, p-a.s)) / (a.e-a.s).len2() );
    return a.a + (((a.b-a.a) * (a.b-a.a).dot(p-a.a)) / ((a.b-a.a).x*(a.b-a.a).x+ (a.b-a.a).y*(a.b-a.a).y) );
}
//点关于直线的对称点
point symmetry (point p, line a)
{
    point q = projection (p, a);
    return point (2*q.x-p.x, 2*q.y-p.y);
}

//point symmetric_point(point p1, point l1, point l2)
//{
//    point ret;
//    if (l1.x > l2.x - eps && l1.x < l2.x + eps)
//    {
//        ret.x = (2 * l1.x - p1.x);
//        ret.y = p1.y;
//    }
//    else
//    {
//        double k = (l1.y - l2.y ) / (l1.x - l2.x);
//        ret.x = (2*k*k*l1.x + 2*k*p1.y - 2*k*l1.y - k*k*p1.x + p1.x) / (1 + k*k);
//        ret.y = p1.y - (ret.x - p1.x ) / k;
//    }
//    return ret;
//}
point c,p0,p1,p2,pb;
int vx,vy;
double r;
int main()
{
//    freopen("in.txt","r",stdin);
freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&c.x,&c.y,&r);
        scanf("%lf%lf%d%d",&p0.x,&p0.y,&vx,&vy);
        scanf("%lf%lf",&pb.x,&pb.y);
        printf("Case #%d: ",cas++);
        line l1;
        l1.a=p0;
        l1.b=point(p0.x+1005*vx,p0.y+1005*vy);
        if(dis(ptoline(c,l1.a,l1.b),c)-r>-eps&&dot_online_in(pb,l1))
        {
            puts("Yes");
            continue;
        }
        else if(dis(ptoline(c,l1.a,l1.b),c)-r>-eps&&!dot_online_in(pb,l1))
        {
            puts("No");
            continue;
        }
        point inters1,inters2;
        intersection_line_circle(c,r,l1.a,l1.b,inters1,inters2);
//        cout<<inters1.x<<" "<<inters1.y<<" "<<inters2.x<<" "<<inters2.y<<endl;
        if(dis(p0,inters1)<dis(p0,inters2))
        {
            p1.x=inters1.x;
            p1.y=inters1.y;
        }
        else
        {
            p1.x=inters2.x;
            p1.y=inters2.y;
        }
        if(dot_online_in(pb,line(p0,p1)))
        {
            puts("Yes");
            continue;
        }
//        cout<<"P1 "<<p1.x<<" "<<p1.y<<endl;
//        p2=symmetric_point(p0,c,p1);
        p2=symmetry(p0,line(c,p1));
//        cout<<"P2 "<<p2.x<<" "<<p2.y<<endl;
        line l2(p1,point(p1.x+(p2.x-p1.x)*1005,p1.y+(p2.y-p1.y)*1005));
        if(dot_online_in(pb,l2))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
