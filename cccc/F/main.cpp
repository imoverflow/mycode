#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long need=ceil(n*0.7);
    int r=n-m;
    printf("%d\n",a);
    if(a<=0)
        printf("0\n");
    else if(r>=a)
        printf("%lld\n",a);
    else
        printf("-1\n");
    long long y=(long long)(1.0*(n-m+k)/n*100);
    printf("%lld\n",y);
    return 0;
}
