#include <iostream>
#include <stdio.h>
#define INF 100000000000000
using namespace std;

double y;
double mul(double a,int b)
{
    double res=1;
    for(int i=0;i<b;i++)
    {
        res*=a;
    }
    return res;
}
double cal(double x)
{
    return 6*(mul(x,7))+8*(mul(x,6))+7*(mul(x,3))+5*(mul(x,2))-y*x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&y);
        double l=0,r=100;
        while(l+1e-7<r)
        {
            double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
            if(cal(lmid)<cal(rmid))
            {
                r=rmid;
            }else
                l=lmid;
        }
        printf("%.4f\n",cal(l));
    }
    return 0;
}
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//double y;
//double val(double x){
//    return 6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-y*x;
//}
//
//double solve(double l,double r){
//    double eps = 1e-7;
//    while(l + eps < r){
//        double lmid = l + (r-l)/3,rmid = r - (r-l)/3;
//        if(val(lmid) < val(rmid)){
//            r = rmid;
//        }else{
//            l = lmid;
//        }
//    }
//    return val(l);
//}
//int main(){
//    int t;
//    cin>>t;
//    while(t--){
//        cin>>y;
//        printf("%.4f\n", solve(0,100.0));
//    }
//    return 0;
//}
