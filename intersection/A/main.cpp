#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator ^(const Point &b)const      //外积
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const      //内积
    {
        return x*b.x + y*b.y;
    }
};
struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y - s.y,e.x - s.x);
    }
    Point operator &(const Line &b)const        //求交点
    {
        Point res = s;
        double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
        res.x += (e.x - s.x)*t;
        res.y += (e.y - s.y)*t;
        return res;
    }
};
//半平面交，直线的左边代表有效区域
bool HPIcmp(Line a,Line b)
{
    if(fabs(a.k - b.k) > eps)
        return a.k < b.k;
    return ((a.s - b.s)^(b.e - b.s)) < 0;
}
Line Q[110];
void HPI(Line line[], int n, Point res[], int &resn)
{
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for(int i = 1;i < n;i++)
        if(fabs(line[i].k - line[i-1].k) > eps)
            line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for(int i = 2; i < tot; i++)
    {
        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps || fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
            return;
        while(head < tail && (((Q[tail]&Q[tail-1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1]) - Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1]) - Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;
    if(tail <= head + 1)
        return;
    for(int i = head; i < tail; i++)
        res[resn++] = Q[i]&Q[i+1];
    if(head < tail - 1)
        res[resn++] = Q[head]&Q[tail];
}
double calArea(Point *res,int n)
{
    if(n<3) return 0;
    double ans=0;
    for(int i=1;i<n-1;i++)
    {
        ans+=(res[i]-res[0])^(res[i+1]-res[0]);
    }
    return fabs(ans);
}
Point point1[105];
Point point2[105];
Point res[105];
Line line1[105];
int main()
{
    int n,m;
    while(~scanf("%d",&n)&&n!=0)
    {
        memset(point1,0,sizeof point1);
        memset(point2,0,sizeof point2);
        memset(res,0,sizeof res);
        memset(line1,0,sizeof line1);
        int resn=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&point1[i].x,&point1[i].y);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%lf%lf",&point2[i].x,&point2[i].y);
        }
        for(int i=0;i<n-1;i++)
        {
//            line1[i].s=point1[i];
//            line1[i].e=point1[i+1];
            line1[i]=Line(point1[i],point1[i+1]);
        }
//        line1[n-1].s=point1[n-1];
//        line1[n-1].e=point1[0];
        line1[n-1]=Line(point1[n-1],point1[0]);
        for(int i=n;i<m+n-1;i++)
        {
//            line1[i].s=point2[i-n];
//            line1[i].e=point2[i+1-n];
            line1[i]=Line(point2[i-n],point2[i+1-n]);
        }
//        line1[m+n-1].s=point2[m-1];
//        line1[m+n-1].e=point2[0];
        line1[m+n-1]=Line(point2[m-1],point2[0]);

//        line1[m+n].s=Point(-1,-1);
//        line1[m+n].e=Point(10000,-1);
//        line1[m+n+1].s=Point(10000,-1);
//        line1[m+n+1].e=Point(10000,10000);
//        line1[m+n+2].s=Point(10000,10000);
//        line1[m+n+2].e=Point(-1,10000);
//        line1[m+n+3].s=Point(-1,10000);
//        line1[m+n+3].e=Point(-1,-1);
        HPI(line1,n+m+4,res,resn);
        printf("%8.2f\n",calArea(res,resn));
    }
    return 0;
}
