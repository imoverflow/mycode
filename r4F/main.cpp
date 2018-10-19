#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long l1,r1,l2,r2,k;
    scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&k);
    if(l1>l2)
    {
        swap(l1,l2);
        swap(r1,r2);
    }
    if(l2<=r1)
        printf("%lld",min(r1,r2)-max(l1,l2)+1-(k>=max(l1,l2)&&k<=min(r1,r2)));
    else
        printf("0");
    return 0;
}
