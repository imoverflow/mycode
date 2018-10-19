#include <stdio.h>
#include <stdlib.h>

int re(int &a,int &b)
{
    return a+b;
}
int main()
{
    int a=1,b=2;
    int p=re(a,b);
    printf("%d",p);
    return 0;
}
