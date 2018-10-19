#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927
using namespace std;

int main()
{
    double a,b,c,d,e,f;
    double t;
    int i,j,k,l,m,n;
    int num[500];
    while(scanf("%lf",&a)!=EOF)
    {
        t=(double)((PI*a*a*a*4)/3);
        printf("%.3lf\n",t);
    }
    return 0;
}
