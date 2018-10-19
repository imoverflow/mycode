#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const double PI=acos(-1);
int main()
{
    long long R,r,L;
    while(~scanf("%lld%lld%lld",&R,&r,&L))
    {
        double ans=4*PI*R*R+4*PI*r*r;
        if(L>=r+R)
        {
            printf("%.10f\n",ans);
            continue;
        }
        double a=acos((1.0*r*r+1.0*L*L-1.0*R*R)/(2*r*L));
        a*=2;
        a/=(2*PI);
        ans-=a*4*PI*r*r;
        double b=acos((1.0*R*R+1.0*L*L-1.0*r*r)/(2*R*L));
        b*=2;
        b/=(2*PI);
        ans-=b*4*PI*R*R;
        printf("%.10f\n",ans);
    }
    return 0;
}
