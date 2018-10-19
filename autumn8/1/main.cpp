#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(const int &a,const int &b)
{
    return a<b;
}
int main()
{
    int a[10]={3,4,2,6,1,8,0,9,5,7};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            if(cmp(a[j],a[j+1]))
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

