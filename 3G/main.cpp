#include <iostream>
#include <stdio.h>
using namespace std;
int twe(int n)
{
    int res=0;
    while(n>0)
    {
        res+=n%12;
        n/=12;
    }
    return res;
}
int ten(int n)
{
    int res=0;
    while(n>0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
int six(int n)
{
    int res=0;
    while(n>0)
    {
        res+=n%16;
        n/=16;
    }
    return res;
}
int main()
{
    for(int i=2992;i<=9999;i++)
    {
        if(twe(i)==ten(i)&&twe(i)==six(i)&&ten(i)==six(i))
            printf("%d\n",i);
    }
    return 0;
}
