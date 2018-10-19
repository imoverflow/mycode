#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int mouth(int n)
{
    switch (n)
    {
    case 1:
        return 31;
    case 2:
        return 29;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int b,c,d,e,sum=0;
        scanf("%d-%d",&b,&c);
        scanf("%d-%d",&d,&e);
        for(int i=b;i<d;i++)
        {
            sum+=mouth(i);
        }
        sum+=e-c;
        printf("%d\n",sum);
    }
    return 0;
}
