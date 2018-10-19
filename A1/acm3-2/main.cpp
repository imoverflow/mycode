#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b,c,d;
    long sum;
    long long s[51];
    s[0]=0;
        s[1]=3;
        s[2]=6;
        s[3]=6;
        for(int i=4;i<=50;i++)
        {
            s[i]=s[i-1]+2*s[i-2];
        }
    while(scanf("%d",&a)!=EOF)
    {

        printf("%lld\n",s[a]);
    }
    return 0;
}
