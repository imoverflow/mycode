#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        long long s[1001];
        scanf("%d",&b);
        for(int j=0;j<b;j++)
        {
            scanf("%lld",&s[j]);
        }
        sort(s,s+b);
        printf("%lld\n",s[b-1]-s[0]);
    }
    return 0;
}
