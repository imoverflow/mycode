#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
void exgcd(long long a,long long b,long long d,long long &x,long long &y)
{
    if(!b){
        d=a;
        x=1;
        y=0;
    }else{
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int main()
{
    int a,b,c,k;
    long long x=0,y=0;
    while(~scanf("%d%d%d%d",&a,&b,&c,&k))
    {
        if(!a&&!b&&!c&&!k)
            break;
        long long p=(long long)1<<k;
        long long t=gcd(p,c);
        if((b-a)%t!=0)
            printf("FOREVER\n");
        else
        {
            exgcd(c,p,t,x,y);
            x=x*(b-a)/t;
            x=(x%(p/t)+(p/t))%(p/t);
            printf("%lld\n",x);
        }
    }
    return 0;
}
