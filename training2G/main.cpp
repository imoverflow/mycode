#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//https://vjudge.net/contest/155101#problem/G
double dis(long long a,long long b,long long c,long long d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long tim ,x,y;
        long long tim1,x1,y1;
        double maxd=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                scanf("%lld%lld%lld",&tim,&x,&y);
            }else
            {
                scanf("%lld%lld%lld",&tim1,&x1,&y1);
                maxd=max(dis(x,y,x1,y1)/(tim1-tim),maxd);
                x=x1;
                y=y1;
                tim=tim1;
            }
        }
        printf("%.10f\n",maxd);
    }
    return 0;
}
