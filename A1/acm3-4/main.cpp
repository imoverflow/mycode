#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b,c;
        long long s1[40]={3};
        long long s2[40]={1};
        for(int i=1;i<40;i++)
        {
            s1[i]=3*s1[i-1]-s2[i-1];
            s2[i]=s1[i-1]-s2[i-1];
        }
    while(scanf("%d",&a)!=EOF)
    {

        printf("%lld\n",s1[a-1]);

    }
    return 0;
}
