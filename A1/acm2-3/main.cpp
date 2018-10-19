#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    long d,n;
    long c,a,i,j,b;
    long s[101];
    while(scanf("%ld",&a)!=EOF)
    {
        d=1;
        for(i=0;i<a;i++)
        {
            scanf("%ld",&b);
            s[i]=b;
            if(b!=0)
            d*=b;
        }
        sort(s,s+a);
        n=d;
        for(i=s[a-1];i<=d;i++)
        {
            c=0;
            for(j=0;j<a;j++)
            {
                if(s[j]!=0)
                {
                    if(i%s[j]==0)
                    {
                        c++;
                    }
                }else{c++;}

            }
            if(c==a)
            {
                printf("%ld\n",i);
                break;
            }
        }
    }
    return 0;
}
