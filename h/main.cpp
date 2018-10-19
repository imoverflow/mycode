#include <iostream>
#include <stdio.h>

using namespace std;

int found=0;
void dfs(long long n,long long k)
{
    if(found==1)
        return ;
    if(k%n==0)
    {
        found=1;
        printf("%lld\n",k);
        return ;
    }
    if(k>111111111111111111)
        return ;
    dfs(n,k*10);
    dfs(n,k*10+1);
}

int main()
{
    long long t;
    while(scanf("%lld",&t)!=EOF)
    {
        if(t==0)
            break;
        found=0;
        dfs(t,1);
    }
    return 0;
}
