#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ExGCD(int a, int b, int& x, int& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = ExGCD(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - a/b*y;
    return d;
}

int main()
{
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    if(d>b)
    {
        swap(a,c);
        swap(b,d);
    }
    int g=ExGCD(a,c,x,y);
    if((d-b)%g!=0)
        puts("-1");
    else
    {
        x*=(d-b)/g;
        int mod=c/g;
        x=(x%mod+mod)%mod;
        printf("%d\n",x);
        printf("%d\n",((d-b)-a*x)/c);
    }
    return 0;
}
