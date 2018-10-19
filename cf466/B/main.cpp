#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n,k,a,b;
long long dfs(long long x)
{
    if(x==1)
        return 0;
    if(x%k==0)
    {
//        long long z=log(n)/log(k)+0.00000001;
        if((x-x/k)*a<b)
            return dfs(x/k)+a*(x-x/k);
        else
            return dfs(x/k)+b;
    }
    else if(x/k!=0)
        return dfs(x-(x%k))+a*(x%k);
    else
        return a*(x-1);
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
    if(k==1)
        printf("%I64d\n",(n-1)*a);
    else
        printf("%I64d\n",dfs(n));
//    long long cost=0;
//    while(n>0)
//    {
//        long long y=n%k;
//        long long x=n/k;
//        cost+=y*a;
//        n-=y;
//        if(x*a+b<)
//    }

    return 0;
}
