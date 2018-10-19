#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <math.h>
using namespace std;

double check(double x){
    return 6*x*x*x+5*x*x+7*x+9;
}
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF){
        double l=-0.000000001,r=10.00000000001;
        int flag=0;
        double ans=-1;
        while(l+1e-12<r){
            double mid=(l+r)/2;
            if(fabs(check(mid)-n)<=1e-8)
            {
                ans=mid;
                flag=1;
                break;
            }else if(check(mid)>n)
                r=mid;
            else if(check(mid)<n)
                l=mid;
        }
        if(flag==1)
        {
            printf("%.4f\n",ans);
        }else{
            printf("No solution!\n");
        }
    }
    return 0;
}
