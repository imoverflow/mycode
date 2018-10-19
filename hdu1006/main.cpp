#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdio.h>
#include<stdio.h>
using namespace std;

long long D;
double hv=1.0/120;
double mv=0.1;
double sv=6;
double hm=0.1-1.0/120,hs=6-1.0/120,ms=6-0.1;
double intersection(double l1,double l2,double l3,double r1,double r2,double r3)
{
    double l=min(l1,min(l2,l3));
    double r=max(r1,max(r2,r3));
    if((360-(r-l))/6<0) return 0;
    return (360-(r-l))/6;
}
double solve(int hh,int mm)
{
    double l1,l2,l3,r1,r2,r3;
    double hpos=hh*30+0.5*mm;
    double mpos=mm*6;
    int hmd=hpos-mpos;
    if(hmd>180) hmd=360-hmd;
    if(hmd<D&&hmd>-D) return 0;
//    if(hpos-D>=0) l1=(hpos-D)/hs*6;
//    else l1=0;
    l1=(hpos-D)/hs*6;
    if((D+hpos)/hs<60) r1=(D+hpos)/hs*6;
    else r1=360;
//    if(mpos-D>=0) l2=(mpos-D)/ms*6;
//    else l2=0;
    l2=(mpos-D)/ms*6;
    if((D+mpos)/ms<60) r2=(D+mpos)/ms*6;
    else r2=360;
    l3=0;
    if(mpos<hpos)
        r3=0;
    else
        r3=min(360.0,(hpos-mpos)/hm*6);
    return intersection(l1,l2,l3,r1,r2,r3);
}
int main()
{
    while(~scanf("%lld",&D)&&D!=-1)
    {
        double sum=0;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                sum+=solve(i,j);
            }
        }
        printf("%.3f\n",sum*2/86400*100);
    }
    return 0;
}
