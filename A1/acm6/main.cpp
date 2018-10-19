#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long a,b,c,d;
    long i,j,k,l;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a>b)
        {
            d=a;
            a=b;
            b=d;
        }
        k=l=0;
        for(i=a;i<=b;i++)
        {
            if(i%2==0)
            {
                k=k+i*i;
            }else{
                l=l+i*i*i;
            }
        }
        printf("%d %d\n",k,l);
    }
    return 0;
}
