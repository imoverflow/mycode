#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
int x[100005];
bool c(int d)
{
    int last=0;
    for(int i=1;i<M;i++)
    {
        int crt=last+1;
        while(crt<N&&x[crt]-x[last]<d)
        {
            crt++;
        }
        if(crt==N) return false;
        last=crt;
    }
    return true;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+N);
    int l=0,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(c(mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}
