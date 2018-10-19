#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        printf("%10d%10d",n,m);
        if(gcd(n,m)==1)
            printf("    Good Choice\n");
        else
            printf("    Bad Choice\n");
        printf("\n");
    }
    return 0;
}
