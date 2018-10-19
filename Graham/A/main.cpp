#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
const double PI = acos(-1.0);

double eps=1e-10;
double add(double a,double b)
{
    if(fabs(a+b)<eps*(fabs(a)+fabs(b))) return 0;     /**考虑误差的加法运算**/
    return a+b;
}
struct P{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator - (P p)                            /**重载-号**/
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    double det(P p)                              /**定义外积**/
    {
        return add(x*p.y,-y*p.x);
    }
};

bool cmp_x(const P& p,const P& q)
{
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> convex_hull(P *ps,int n)            /**抄模板**/
{
    sort(ps,ps+n,cmp_x);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;i++)
    {
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--)
    {
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
int n;
double dis(vector<P> v)                        /**计算凸包边长**/
{
    double ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        ans+=sqrt((v[i].x-v[i+1].x)*(v[i].x-v[i+1].x)+(v[i].y-v[i+1].y)*(v[i].y-v[i+1].y));
    }
    ans+=sqrt((v[0].x-v[v.size()-1].x)*(v[0].x-v[v.size()-1].x)+(v[0].y-v[v.size()-1].y)*(v[0].y-v[v.size()-1].y));
    return ans;
}
P ps[1005];
int main()
{
    int r;
    scanf("%d%d",&n,&r);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ps[cnt].x=a;
        ps[cnt++].y=b;
    }
    vector<P> pp=convex_hull(ps,n);
//    printf("%f\n",PI);
//    printf("%f\n",dis(pp));
    printf("%lld",(long long)(dis(pp)+0.5+PI*r*2));
    return 0;
}
