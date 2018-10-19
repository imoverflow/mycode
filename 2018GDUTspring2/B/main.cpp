#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
double EPS=1e-10;

double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){
    }
    point operator +(point p)
    {
        return point(add(x,p.x),add(y,p.y));
    }
    point operator -(point p)
    {
        return point(add(x,-p.x),add(y,-p.y));
    }
    point operator *(double d)
    {
        return point(x*d,y*d);
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
double cross_product(point x,point y,point z)
{
    return (z-x).det(z-y);
}
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

/****************/
/**  旋转卡壳  **/
/****************/
double rotating_caliper(vector<point> v)
{
    double min_dis = INF;
    int n = v.size();
    v.push_back(v[0]);
    for (int i = 0; i < n; ++i)
    {
        double res=0;
        for(int j=0;j<n;j++)
        {
            res=max(res,cross_product(v[i],v[i+1],v[j])/dis(v[i],v[i+1]));
        }
        min_dis = min(min_dis,res);
     }
     return min_dis;
/*****************************************************************************************************/
/***                           优化的思路 但是莫名tle了                                           ***/
/**    int j = 2;                                                                                  ***/
/**    for (int i = 0; i < n; ++i)                                                                 ***/
/**    {                                                                                           ***/
/**      while (cross_product(v[i], v[i + 1], v[j]) < cross_product(v[i], v[i + 1], v[j + 1]))     ***/
/**      {                                                                                         ***/
/**          j = (j + 1) % n;                                                                      ***/
/**      }                                                                                         ***/
/**       min_dis = max(min_dis,cross_product(v[i],v[i+1],v[j])/dis(v[i],v[i+1]) );                ***/
/**    }                                                                                           ***/
/*****************************************************************************************************/
}

/****************/
/**  计算凸包  **/
/****************/

bool cmp(const point& p,const point& q)
{
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<point> convex_hull(point *ps,int n)
{
    sort(ps,ps+n,cmp);
    int k=0;
    vector<point> qs(n*2);
    for(int i=0;i<n;i++)
    {
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--)
    {
        while(k>t&& (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
point ps[105];
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ps[cnt++]=point(a,b);
    }
    vector<point> qs=convex_hull(ps,n);
    double res=rotating_caliper(qs);
    printf("%.10f\n",res);
    return 0;
}
