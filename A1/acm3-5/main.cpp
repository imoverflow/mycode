#include <iostream>
#include <stdio.h>
using namespace std;

long long st(int b)
{
    long long sum=1;
    for(int i=1;i<=b;i++)
    {
        sum*=i;
    }
    return sum;
}

int main()
{
    int a,b,c;
    double m,n,p,q;
    double s[21]={0,0,1};
    for(int i=3;i<=20;i++)
        {
            s[i]=(i-1)*(s[i-1]+s[i-2]);
        }
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&b);
        m=s[b]/st(b);
        printf("%.2f%%\n",m*100);

    }
    return 0;
}
