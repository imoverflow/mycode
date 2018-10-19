#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b,c,d,e,sum;
    int i,j,k,l;
    while(scanf("%d",&a)!=EOF)
    {
        sum=1;
        for(i=0;i<a;i++)
        {
            scanf("%d",&b);
            if(b%2!=0&&b!=0)
            {
                sum=sum*b;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
