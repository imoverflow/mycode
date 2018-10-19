#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d",&a);
    c=0;
    for(int i=2;i*i<a;i++)
    {
        if(a%i==0)
        {
            c=1;
        }
    }
    if(c==1)
        printf("NO");
    else
        printf("YES");
}
