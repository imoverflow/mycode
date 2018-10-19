#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    int n;
    double a=0;
    double s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a+=(double)i*(pow(10.0,(long)(i-1)));
        s+=a;
        printf("%.0f\n",a);

    }
    printf("%.0f",s);
    return 0;
}
