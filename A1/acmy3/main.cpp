#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int cou=0;
        scanf("%d %d %d",&b,&c,&d);
        int s[1005]={0};
        for(int j=0;j<d;j+=b)                   //d
        {
            s[j]++;
        }
        for(int j=0;j<d;j+=c)                   //d
        {
            s[j]++;
        }
        for(int j=1;j<d;j++)
        {
            if(s[j]==2)
                cou++;
        }
        printf("%d\n",36*cou);
    }
    return 0;
}
