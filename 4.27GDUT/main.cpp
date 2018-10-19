#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long ans[1000005];
int main()
{
    int t;
    cin>>t;
    fill(ans,ans+t+1,-1);
    for(long long i=0;i<t;i++)
    {
        ans[i*i%t]=i;
    }
    for(int i=0;i<t;i++)
    {
        if(i==0)
            printf("0");
        else
            printf(" %lld",ans[i]);
    }
    return 0;
}
