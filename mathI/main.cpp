#include <iostream>
#include <stdio.h>
using namespace std;

long long s[100];
int main()
{
    s[2]=1;
    s[3]=2;
    for(int i=4;i<21;i++)
    {
        s[i]=(i-1)*(s[i-1]+s[i-2]);
    }
    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",s[n]);
    }
    return 0;
}
