#include <iostream>
#include <stdio.h>
using namespace std;

double a,b,c;
double check(double m)
{
    return a-(a-b)*c/m + c-m;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        double l=c-b*c/a,r=c,ans;
        while(l+1e-8<r)
        {
            double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
            double x1=check(lmid);
            double x2=check(rmid);
            if(x1<x2)
            {
                l=lmid;
                ans=x2;
            }
            else
            {
                r=rmid;
                ans=x1;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
