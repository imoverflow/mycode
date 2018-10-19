#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long x,long long y)
{
    long long ans=x/y;
    if(x>0&&x%y) ans++;
    return ans;
}
long long a[100000];
long long b[100000];
int main()
{
    long long p,k;
    scanf("%I64d%I64d",&p,&k);
    int num=1;
    b[0]=ceil_div(-p,k);
    a[0]=k*b[0]+p;
    for(int i=1;i<10000;i++)
    {
        b[i]=ceil_div(-b[i-1],k);
        a[i]=k*b[i]+b[i-1];
        if(a[i]) num=i+1;
    }
    printf("%d\n",num);
    for(int i=0;i<num;i++)
    {
        printf("%I64d ",a[i]);
    }
    return 0;
}
