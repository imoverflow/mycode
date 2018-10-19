#include <iostream>
#include <stdio.h>
using namespace std;
long long gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
long long gcm(int x,int y)
{
    return (long long)(x*y)/gcd(x,y);
}
int main()
{
    int t;
    int a,b,c,d;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(  d%gcm(a,b)==0|| d%gcm(a,c)==0|| d%gcm(b,c)==0 || d%(gcm(a,gcm(b,c)))==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
