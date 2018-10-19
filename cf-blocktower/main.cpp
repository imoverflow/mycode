#include <iostream>
#include <stdio.h>
using namespace std;
//http://codeforces.com/contest/626/problem/C
int a,b;
bool check(int x)
{
    int num1=x/2;
    int num2=x/3;
    int num3=x/6;
    if(num1<a) return false;
    if(num2<b) return false;
    if(num1+num2-num3<a+b) return false;
    return true;
}
int main()
{
    scanf("%d%d",&a,&b);
    int l=0,r=1e7,ans=0,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
