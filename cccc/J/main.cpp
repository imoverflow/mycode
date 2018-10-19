#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;

struct node{
    long long x,y,r;
}s[1005];

bool dis(node a,node b)
{
    int d=a.r+b.r;
    double rr=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    if(rr-d<0.000001)
        return true;
    else
        return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].r);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dis(s[i],s[j]))
            {
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}
