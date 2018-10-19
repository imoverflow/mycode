#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;

long long s[3][100005];
int n;

long long cal(long long a[100005],long long b[100005])
{
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(a[i]-b[i])*(a[i]-b[i]);
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&s[i][j]);
        }
    }
    long long p1=cal(s[0],s[1]);
    long long p2=cal(s[0],s[2]);
    if(p1<=p2)
        printf("Yan\n");
    else
        printf("MaratonIME\n");
    return 0;
}
