#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double dis(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double mind(double a,double b)
{
    return a<b?a:b;
}
int main()
{
    double x1,x2,y1,y2,vx1,vy1,vx2,vy2;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&vx1,&vy1,&vx2,&vy2);
    double ds=dis(x1,x2,y1,y2);
    double l=0,r=100000000;
    double ans;
    while(r-l>1e-10)
    {
        double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        double disl=dis(x1+vx1*lmid,x2+vx2*lmid,y1+vy1*lmid,y2+vy2*lmid);
        double disr=dis(x1+vx1*rmid,x2+vx2*rmid,y1+vy1*rmid,y2+vy2*rmid);
        if(disl<disr)
        {
            ans=disl;
            r=rmid;
        }else{
            ans=disr;
            l=lmid;
        }
    }
    printf("%.10f\n",mind(ans,ds));
    return 0;
}
