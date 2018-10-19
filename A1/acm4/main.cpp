#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int y,m,d,r,sum;
    int i,j,k;
    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        int day(int month);
        r=0;
        sum=0;
        if(y%4==0&&y%100!=0)
            r=1;
        if(y%400==0)
            r=1;
        for(i=1;i<m;i++)
        {
            sum+=day(i);
        }
        if(m>2)
        {
            printf("%d\n",sum+r+d);
        }else{
            printf("%d\n",sum+d);
        }

    }
    return 0;
}

int day(int month)
{
    switch(month)
    {
    case(1):
        return 31;
        break;
    case(2):
        return 28;
        break;
    case(3):
        return 31;
        break;
    case(4):
        return 30;
        break;
    case(5):
        return 31;
        break;
    case(6):
        return 30;
        break;
    case(7):
        return 31;
        break;
    case(8):
        return 31;
        break;
    case(9):
        return 30;
        break;
    case(10):
        return 31;
        break;
    case(11):
        return 30;
        break;
    case(12):
        return 31;
        break;
    }
}
