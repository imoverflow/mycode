#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
 #include <string.h>
using namespace std;

int main()
{
    int a,c,b,d;
    int i,j,k,l;
    char s[100];
    while(scanf("%d",&a)!=EOF)
    {
        for(i=0;i<a;i++)
        {
            d=0;
            scanf("%s",s);
            for(j=0;j<strlen(s);j++)
            {
                if(s[j]>='0'&&s[j]<='9')
                    d++;
            }
            printf("%d\n",d);
        }
    }
    return 0;
}
