#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int year(int n,int m);
int mouth(int n,int y)
{
    if(year(y,n)==366)
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
    }else
    {
        switch (n)
    {
    case 1:
        return 31;
    case 2:
        return 28;
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

}
int year(int n,int m)
{
    if(n%4==0&&n%100!=0&&m<2)
        return 366;
    if(n%100==0&&n%400==0)
        return 366;
    return 365;
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int b,c,d,e,sum=0;
        scanf("%d%d%d",&b,&c,&d);
        for(int j=b;j<2017;j++)
        {
            sum+=year(j,c);
            for(int k=c;k<10;k++)
            {
                sum+=mouth(k,j);
            }
        }

        sum+=28-d;
        printf("%d\n",sum);
    }
    return 0;
}
