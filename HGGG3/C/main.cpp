#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,ans=0;
        scanf("%lf%lf",&a,&b);
        if(a-b<=1e-8)
            printf("0.000000\n");
        else
            printf("%.6f\n",log(a/b)+1);
    }
    return 0;
}
