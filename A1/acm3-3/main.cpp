#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    long long s[51]={0,1,2,3};
    for(int i=4;i<51;i++)
    {
        s[i]=s[i-1]+s[i-2];
    }
    while(scanf("%d",&a)!=EOF)
    {
        printf("%lld\n",s[a]);
    }

    return 0;
}
