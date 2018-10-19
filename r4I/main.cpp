#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    double n,s[300];
    s[0]=0;
    for(int i=1;i<300;i++)
    {
        s[i]=s[i-1]+1.0/(i+1);
    }
    while(scanf("%lf",&n)!=EOF)
    {
        if(fabs(n)<1e-3)
            break;
        for(int i=0;i<300;i++)
        {
            if(n<=s[i])
            {
                printf("%d ",i);
                printf("card(s)\n");
                break;
            }
        }
    }
    return 0;
}
