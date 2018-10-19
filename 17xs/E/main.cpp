#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("20.in","r",stdin);
    int n;
    scanf("%d",&n);
    double ans=0;
    for(int i=0;i<n;i++)
    {
        char t;
        scanf(" %c",&t);
        if(t=='T')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ans=max(ans,0.5*a*b);
        }else if(t=='R')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ans=max(ans,(double)a*b);
        }else{
            int a;
            scanf("%d",&a);
            ans=max(ans,3.14159*a*a);
        }
//        getchar();
    }
    printf("%.2f\n",ans+0.005);
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        double a,b,c;
//        scanf("%lf%lf%lf",&a,&b,&c);
//        printf("%.3f\n",a*c/(a*c+b*(1-c)));
//    }
    return 0;
}
