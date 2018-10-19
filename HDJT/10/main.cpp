#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    while(~scanf("%lf",&n))
    {
        int flag=0;
        if(fabs(n-1)<1e-7)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<5;i++)
        {
            n=floor(sqrt(n));
            if(fabs(n-1)<1e-7)
            {
                printf("%d\n",i+1);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("QAQ\n");
        }
    }
    return 0;
}
