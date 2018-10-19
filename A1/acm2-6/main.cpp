#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0&&b==0)
            exit(0);
        c=1;
        for(int i=0;i<b;i++)
        {
            c=a*c;
            c=c%1000;
        }
        printf("%d\n",c);
    }
    return 0;
}
