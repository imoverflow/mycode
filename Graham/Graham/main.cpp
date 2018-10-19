#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

double eps=1e-10;
double add(double a,double b)
{
    if(abs(a+b)<eps*(abs(a)+abs(b))) return 0;     /**�������ļӷ�����**/
    return a+b;
}
struct P{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator - (P p)                            /**����-��**/
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    double det(P p)                              /**�������**/
    {
        return add(x*p.y,-y*p.x);
    }
};

bool cmp_x(const P& p,const P& q)
{
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> convex_hull(P *ps,int n)            /**��ģ��**/
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
double dis(vector<P> v)                        /**����͹���߳�**/
{
    double ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        ans+=sqrt((v[i].x-v[i+1].x)*(v[i].x-v[i+1].x)+(v[i].y-v[i+1].y)*(v[i].y-v[i+1].y));
    }
    ans+=sqrt((v[0].x-v[v.size()-1].x)*(v[0].x-v[v.size()-1].x)+(v[0].y-v[v.size()-1].y)*(v[0].y-v[v.size()-1].y));
    return ans;
}
char s[25];
int N;
int n;
int findnotT(int dir)    // 1 left 2 right
{                                       /**�������һ���������Ҳ��������ε���״**/
    int ans=-1;
    if(dir==1)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='T')
            {
                ans=i;
                break;
            }
        }
    }else{
        for(int i=0;i<n;i++)
        {
            if(s[i]!='T')
            {
                ans=i;
                break;
            }
        }
    }
    return ans;
}
P ps[100];
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        int cnt=0;
        for(int pos=0;pos<n;pos++)
        {
            if(s[pos]=='C')                      /**Բ�ε��������ߵ����͵����**/
            {
                ps[cnt].x=pos+0.5;
                ps[cnt++].y=0;
                ps[cnt].x=pos+0.5;
                ps[cnt++].y=1;
            }else if(s[pos]=='T')
            {
                ps[cnt].x=pos;
                ps[cnt++].y=0;
                ps[cnt].x=pos+0.5;
                ps[cnt++].y=sqrt(3)/2;
                ps[cnt].x=pos+1;
                ps[cnt++].y=0;
            }else{
                ps[cnt].x=pos;
                ps[cnt++].y=0;
                ps[cnt].x=pos;
                ps[cnt++].y=1;
                ps[cnt].x=pos+1;
                ps[cnt++].y=0;
                ps[cnt].x=pos+1;
                ps[cnt++].y=1;
            }
        }
        vector<P> pp=convex_hull(ps,cnt);
        double ans=dis(pp);
        if(s[0]=='C')                       /**��Ϊ��������ʱ���Բ�����߶δ���������������һ��**/
        {
            ans=ans-1+PI/2;
        }
        if(s[n-1]=='C')
        {
            ans=ans-1+PI/2;
        }
        if(s[0]=='T')
        {
            int index=findnotT(2);
            if(index!=-1)
            {
                if(s[index]=='C')            /**���������κ�Բ�����γɵĳ���**/
                {
                    ans=ans-sqrt(index*index+(1-sqrt(3)/2)*(1-sqrt(3)/2));
                    double t0=sqrt(index*index+(0.5-sqrt(3)/2)*(0.5-sqrt(3)/2));
                    double af1=atan((sqrt(3)/2-0.5)/index);
                    double af2=acos(0.5/t0);
                    double af=PI/2-af1-af2;
                    ans+=sqrt(t0*t0-0.25);
                    ans+=af/2;
                }
            }
        }
        if(s[n-1]=='T')
        {
            int index=findnotT(1);
            if(index!=-1)
            {
                if(s[index]=='C')
                {
                    ans=ans-sqrt((n-index-1)*(n-index-1)+(1-sqrt(3)/2)*(1-sqrt(3)/2));
                    double t0=sqrt((n-index-1)*(n-index-1)+(0.5-sqrt(3)/2)*(0.5-sqrt(3)/2));
                    double af1=atan((sqrt(3)/2-0.5)/(n-index-1));
                    double af2=acos(0.5/t0);
                    double af=PI/2-af1-af2;
                    ans+=sqrt(t0*t0-0.25);
                    ans+=af/2;
                }
            }
        }
        printf("%.12f\n",ans);
    }
    return 0;
}
