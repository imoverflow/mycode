//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//#define MAXN 1005
//#define offset 1000000
//#define eps 1e-8
//const double INF = 1e18;
//int N;
////浮点数判 0
//#define zero(x) (((x)>0?(x):-(x))<eps)
//
////浮点数判断符
//#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
//
////定义点
//struct point {     double x,y; }pt[MAXN ];
//
//point s[MAXN];
////定义线段
//struct line {     point a,b; };
//
////叉积
//double d2r(double d)
//{
//    return d/180*cos(-1.0);
//}
//double xmult(point p1,point p2,point p0) {     return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y); }
//int inside_convex_v2(point q,int n,point* p)
//{
//    int i,s[3]={1,1,1};
//    for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
//        s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
//    return s[0]&&s[1]|s[2];
//}
//int inside_convex(point q,int n,point* p)
//{
//    int i,s[3]={1,1,1};
//    for (i=0;i<n&&s[1]|s[2];i++)
//        s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
//    return s[1]|s[2];
//}
//double in3(double edge)
//{
//    point pp[3];
//    pp[0].x=edge*sqrt(3)/3             ,pp[0].y=0;
//    pp[1].x=-edge*sqrt(3)/3            ,pp[1].y=0.5*edge;
//    pp[2].x=-edge*sqrt(3)/3            ,pp[2].y=-0.5*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],3,pp)==1) return INF;
//    }
//    return sqrt(3)/8*edge*edge;
//}
//double out3(double edge)
//{
//    point pp[3];
//    pp[0].x=edge*sqrt(3)/3,pp[0].y=0;
//    pp[1].x=-edge*sqrt(3)/3,pp[1].y=0.5*edge;
//    pp[2].x=-edge*sqrt(3)/3,pp[2].y=-0.5*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],3,pp)==0) return INF;
//    }
//    return sqrt(3)/8*edge*edge;
//}
//double in4(double edge)
//{
//    point pp[4];
//    pp[0].x=sqrt(2)/2*edge             ,pp[0].y=0;
//    pp[1].x=0                          ,pp[1].y=sqrt(2)/2*edge;
//    pp[2].x=-sqrt(2)/2*edge            ,pp[2].y=0;
//    pp[3].x=0                          ,pp[3].y=-sqrt(2)/2*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],4,pp)==1) return INF;
//    }
//    return edge*edge;
//}
//double out4(double edge)
//{
//    point pp[4];
//    pp[0].x=sqrt(2)/2*edge,pp[0].y=0;
//    pp[1].x=0,pp[1].y=sqrt(2)/2*edge;
//    pp[2].x=-sqrt(2)/2*edge,pp[2].y=0;
//    pp[3].x=0,pp[3].y=-sqrt(2)/2*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],5,pp)==0) return INF;
//    }
//    return edge*edge;
//}
//double in5(double edge)
//{
//    point pp[5];
//    pp[0].x=1.0/(2*cos(d2r(54)))*edge                  ,pp[0].y=0    ;
//    pp[1].x=(1.0/(2*cos(d2r(54)))-cos(d2r(54)))*edge   ,pp[1].y=tan(d2r(54))*cos(d2r(54))*edge    ;
//    pp[2].x=-0.5*tan(d2r(54))*edge                     ,pp[2].y=0.5*edge    ;
//    pp[3].x=-0.5*tan(d2r(54))*edge                     ,pp[3].y=0.5*edge    ;
//    pp[4].x=(1.0/(2*cos(d2r(54)))-cos(d2r(54)))*edge   ,pp[4].y=-tan(d2r(54))*cos(d2r(54))*edge    ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],5,pp)==1) return INF;
//    }
//    return 0.5*sin(d2r(72))-edge*edge/(2-2*cos(d2r(72)));
//}
//double out5(double edge)
//{
//    point pp[5];
//    pp[0].x=1.0/(2*cos(d2r(54)))*edge   ,pp[0].y=0    ;
//    pp[1].x=(1.0/(2*cos(d2r(54)))-cos(d2r(54)))*edge   ,pp[1].y=tan(d2r(54))*cos(d2r(54))*edge    ;
//    pp[2].x=-0.5*tan(d2r(54))*edge  ,pp[2].y=0.5*edge    ;
//    pp[3].x=-0.5*tan(d2r(54))*edge   ,pp[3].y=0.5*edge    ;
//    pp[4].x=(1.0/(2*cos(d2r(54)))-cos(d2r(54)))*edge   ,pp[4].y=-tan(d2r(54))*cos(d2r(54))*edge    ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],5,pp)==0) return INF;
//    }
//    return 0.5*sin(d2r(72))-edge*edge/(2-2*cos(d2r(72)));
//}
//double in6(double edge)
//{
//    point pp[6];
//    pp[0].x=edge,          pp[0].y=0;
//    pp[1].x=0.5*edge,      pp[1].y=sqrt(3)/2*edge;
//    pp[2].x=-0.5*edge,     pp[2].y=sqrt(3)/2*edge;
//    pp[3].x=-edge,         pp[3].y=0;
//    pp[4].x=-0.5*edge,     pp[4].y=-sqrt(3)/2*edge;
//    pp[5].x=0.5*edge,      pp[5].y=-sqrt(3)/2*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],6,pp)==1) return INF;
//    }
//    return 6*sqrt(3)/8*edge*edge;
//}
//double out6(double edge)
//{
//    point pp[6];
//    pp[0].x=edge, pp[0].y=0;
//    pp[1].x=0.5*edge,pp[1].y=sqrt(3)/2*edge;
//    pp[2].x=-0.5*edge,pp[1].y=sqrt(3)/2*edge;
//    pp[3].x=-edge, pp[3].y=0;
//    pp[4].x=-0.5*edge,pp[4].y=-sqrt(3)/2*edge;
//    pp[5].x=0.5*edge,pp[1].y=-sqrt(3)/2*edge;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],6,pp)==0) return INF;
//    }
//    return 6*sqrt(3)/8*edge*edge;
//}
//double in7(double edge)
//{
//    point pp[7];
//    double alp=d2r(180-360.0/7);
//    pp[0].x=1.0/(2*cos(alp))*edge                                        ,pp[0].y=0       ;
//    pp[1].x=edge*sqrt((1/(4*cos(alp)*cos(alp)))-sin(alp)*sin(alp))       ,pp[1].y=sin(alp)*edge       ;
//    pp[2].x=-cos(d2r(360*3/14.0))*edge/(2*cos(alp))                      ,pp[2].y=edge*sin(d2r(360*3/14.0))/(2*cos(alp))       ;
//    pp[3].x=-1/(2*tan(alp))*edge                                         ,pp[3].y=0.5*edge       ;
//    pp[4].x=-1/(2*tan(alp))*edge                                         ,pp[4].y=-0.5*edge       ;
//    pp[5].x=-cos(d2r(360*3/14.0))*edge/(2*cos(alp))                      ,pp[5].y=-edge*sin(d2r(360*3/14.0))/(2*cos(alp))       ;
//    pp[6].x=edge*sqrt((1/(4*cos(alp)*cos(alp)))-sin(alp)*sin(alp))       ,pp[6].y=-sin(alp)*edge         ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],7,pp)==1) return INF;
//    }
//    return 7.0/4*tan(alp)*edge*edge;
//}
//double out7(double edge)
//{
//    point pp[7];
//    double alp=d2r(180-360.0/7);
//    pp[0].x=1.0/(2*cos(alp))*edge       ,pp[0].y=0       ;
//    pp[1].x=edge*sqrt((1/(4*cos(alp)*cos(alp)))-sin(alp)*sin(alp))       ,pp[1].y=sin(alp)*edge       ;
//    pp[2].x=-cos(d2r(360*3/14.0))*edge/(2*cos(alp))       ,pp[2].y=edge*sin(d2r(360*3/14.0))/(2*cos(alp))       ;
//    pp[3].x=-1/(2*tan(alp))*edge       ,pp[3].y=0.5*edge       ;
//    pp[4].x=-1/(2*tan(alp))*edge       ,pp[4].y=-0.5*edge       ;
//    pp[5].x=-cos(d2r(360*3/14.0))*edge/(2*cos(alp))        ,pp[5].y=-edge*sin(d2r(360*3/14.0))/(2*cos(alp))       ;
//    pp[6].x=edge*sqrt((1/(4*cos(alp)*cos(alp)))-sin(alp)*sin(alp))       ,pp[6].y=-sin(alp)*edge         ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],7,pp)==0) return INF;
//    }
//    return   7.0/4*tan(alp)*edge*edge;
//}
//double in8(double edge)
//{
//    point pp[8];
//    double x=2*tan(d2r(45.0/2)),y=0.5;
//    pp[0].x=edge*x        ,pp[0].y=y*edge       ;
//    pp[1].x=edge*y        ,pp[1].y=x*edge       ;
//    pp[2].x=-y*edge       ,pp[2].y=x*edge       ;
//    pp[3].x=-x*edge       ,pp[3].y=y*edge       ;
//    pp[4].x=-x*edge       ,pp[4].y=-y*edge       ;
//    pp[5].x=-y*edge       ,pp[5].y=-x*edge       ;
//    pp[6].x=y*edge        ,pp[6].y=-x*edge       ;
//    pp[7].x=x*edge        ,pp[7].y=-y*edge      ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex_v2(s[i],8,pp)==1) return INF;
//    }
//    return   2*tan(d2r(67.5))*edge*edge;
//}
//double out8(double edge)
//{
//    point pp[8];
//    double x=2*tan(d2r(45.0/2)),y=0.5;
//    pp[0].x=edge*x       ,pp[0].y=y*edge       ;
//    pp[1].x=edge*y       ,pp[1].y=x*edge       ;
//    pp[2].x=-y*edge       ,pp[2].y=x*edge       ;
//    pp[3].x=-x*edge       ,pp[3].y=y*edge       ;
//    pp[4].x=-x*edge       ,pp[4].y=-y*edge       ;
//    pp[5].x=-y*edge       ,pp[5].y=-x*edge       ;
//    pp[6].x=y*edge       ,pp[6].y=-x*edge       ;
//    pp[7].x=x*edge       ,pp[7].y=-y*edge      ;
//    for(int i=0;i<N;i++)
//    {
//        if(inside_convex(s[i],8,pp)==0) return INF;
//    }
//    return   2*tan(d2r(67.5))*edge*edge;
//}
//double t1(double (*x1)(double))
//{
//    double l=0,r=1e6;
//    double ans=0;
//    while(r-l>1e-7)
//    {
//        double mid=(l+r)/2;
//        double p=x1(mid);
//        if(fabs(p-INF)>1e-7)
//        {
//            if(ans>p)
//            {
//                l=mid;
//            }else{
//                r=mid;
//                ans=p;
//            }
//        }else{
//            r=mid;
//        }
//    }
//    return ans;
//}
//double t2(double (*x1)(double))
//{
//    double l=0,r=1e6;
//    double ans=INF;
//    while(r-l>1e-7)
//    {
//        double mid=(l+r)/2;
//        double p=x1(mid);
//        if(fabs(p-INF)>1e-7)
//        {
//            if(ans>p)
//            {
//                r=mid;
//                ans=p;
//            }else{
//                l=mid;
//            }
//        }else{
//            l=mid;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    N=n;
//    for(int i=0;i<n;i++)
//    {
//        scanf("%lf%lf",&s[i].x,&s[i].y);
//    }
//    double ans1=0,ans2=INF;
//    ans1=max(ans1,t1(in3));
//    ans1=max(ans1,t1(in4));
//    ans1=max(ans1,t1(in5));
//    ans1=max(ans1,t1(in6));
//    ans1=max(ans1,t1(in7));
//    ans1=max(ans1,t1(in8));
//    ans2=min(ans2,t2(out3));
//    ans2=min(ans2,t2(out4));
//    ans2=min(ans2,t2(out5));
//    ans2=min(ans2,t2(out6));
//    ans2=min(ans2,t2(out7));
//    ans2=min(ans2,t2(out8));
//    printf("%f %f\n",ans1,ans2);
//    printf("%10f",ans1/ans2);
//    return 0;
//}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long n,m,k;
    while(~scanf("%lld%lld%lld",&n,&m,&k))
    {
        if(k==-1 && ((n%2)^(m%2))==1)
        {
            printf("Orz\n");
        }else{
            printf("O(^_^)O~~\n");
        }
    }
    return 0;
}
