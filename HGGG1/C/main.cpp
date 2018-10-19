#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int r;
double dis(int a,int b)
{
    return sqrt(a*a+b*b);
}
int f(int a,int b)
{
    if(fmod(dis(a,b),r)<1e-6&&fabs(dis(a,b))>1e-6)
    {
        return max(0,10-(int)dis(a,b)/r+1);
    }else{
        return max(0,10-(int)dis(a,b)/r);
    }
}
int main()
{

    scanf("%d",&r);
    int ans=0;
    for(int i=0;i<3;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ans+=f(a,b);
    }
    printf("%d\n",ans);
    return 0;
}
