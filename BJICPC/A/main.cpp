#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

double eps=1e-10;
double add(double a,double b)
{
    if(abs(a+b)<eps*(abs(a)+abs(b))) return 0;     /**考虑误差的加法运算**/
    return a+b;
}
struct P{
    double x,y;
    int pos;
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
char s[25];
int N;
int n;
P ps[110];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ps[i].pos=i;
            ps[i].x=a;
            ps[i].y=b;
        }
        if(n<3)
        {
            printf("NO\n");
            continue;
        }
        vector<P> ans=convex_hull(ps,n);
        bool A[200]={false};
        for(int i=0;i<ans.size();i++)
        {
            A[ans[i].pos]=true;
        }
        if(ans.size()==n)
        {
            if(ans.size()==3)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
//            for(int i=0;i<n;i++)
//            {
//                printf("%f %f\n",ans[i].x,ans[i].y);
//            }
            int vv[1005]={0};
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                    vv[ans[i].pos]=1;
                else
                    vv[ans[i].pos]=2;
            }
            for(int i=0;i<n;i++)
            {
                if(vv[i]==1)
                    printf("A");
                else
                    printf("B");
            }
            printf("\n");
        }else{
            printf("YES\n");
            for(int i=0;i<n;i++)
            {
                if(A[i])
                    printf("A");
                else
                    printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}
