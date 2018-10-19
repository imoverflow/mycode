#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
double eps=1e-10;
double add(double a,double b)
{
    if(abs(a+b)<eps*(abs(a)+abs(b))) return 0;     /**考虑误差的加法运算**/
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
double area(vector<P> v)
{
//    if(r-l+1<3) return 0;
//    double ans=0;
//    for(int i=l+1;i+1<r;i++)
//    {
//        ans+=fabs(0.5*( (v[i]-v[l]).det(v[i+1]-v[l]) ));
//    }
//    return fabs(ans);
    if(v.size()<3) return 0;
    double ans=0;
    for(int i=1;i+1<v.size();i++)
    {
        ans+=0.5*(v[0]-v[i]).det(v[0]-v[i+1]);
    }
    return fabs(ans);
}
int n;
P ps[100005];
double check(int x)
{
//    int i;
//    for(i=0;i<n;i++)
//    {
//        if(ps[i].x<=ps[x].x) continue;
//        else break;
//    }
//    return area(ps,0,i)+area(ps,i,n);
    vector<P> p1;
    int i;
    for(i=0;i<n;i++)
    {
        if(ps[i].x<=x) continue;
        else break;
    }
    if(i!=0&&i!=n)
        return area(convex_hull(ps,i))+area(convex_hull(ps+i,n-i));
    else
        return area(convex_hull(ps,n));
}
map<int,int>ma;

int main()
{
    scanf("%d",&n);
    memset(ps,0,sizeof ps);
    ma.clear();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ps[cnt].x=a;
        ps[cnt++].y=b;
    }
    sort(ps,ps+n,cmp_x);
    double ans=INF;
    int l=-1e9,r=1e9;
    int flag=0;
    double eps=1e-7;
    while(l+1<r)
    {
//        if(flag++>1e4) break;
        int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        double ans1=check(lmid),ans2=check(rmid);
        if(ans1-ans2<-eps)
        {
            r=rmid-1;
            ans=min(ans1,ans);
        }else if(ans1-ans2>eps){
            l=lmid+1;
            ans=min(ans2,ans);
        }else
        {
            ans=min(ans1,ans);
            l=lmid+1;
            r=rmid;
        }
    }
    printf("%lld\n",(long long)(ans+0.5));
    return 0;
}
