#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{

    int g,h,i,j,k,l,sum;
    int m,n,o,p;
    int s[101];
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
            exit(0);
        for(p=0;p<m;p++)
        {
            scanf("%d",&n);
            s[p]=n;
        }
        sum=0;
        for(g=0;g<m;g++)
        {
            h=s[g]/100;
            i=(s[g]-h*100)/50;
            j=(s[g]-100*h-50*i)/10;
            k=(s[g]-100*h-50*i-j*10)/5;
            l=(s[g]-100*h-50*i-j*10-k*5)/2;
            n=s[g]-100*h-50*i-j*10-k*5-l*2;
            sum=sum+h+i+j+k+l+n;
        }
        printf("%d\n",sum);

    }
    return 0;
}
