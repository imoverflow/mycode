#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
double y;
double cal(double x)
{
    return 8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lf",&y);
        double l=0,r=100;
        while(l+1e-8<r)
        {
            double mid=(l+r)/2;
            if(cal(mid)-y>=0)
            {
                r=mid;
            }else
                l=mid;
        }
        if(y<6||y>cal(100))
            printf("No solution!\n");
        else
            printf("%.4f\n",l);
    }
    return 0;
}
