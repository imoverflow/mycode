#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b,c;
    double m,n,p,q;
    long long s[21]={0,1};
    for(int i=3;i<=20;i++)
        {
            s[i]=(i-1)*(s[i-1]+s[i-2]);
        }
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&b,&c);
        printf("%lld\n",s[b]);

    }
    return 0;
}
