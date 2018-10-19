#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long n,m,k;
    while(~scanf("%lld%lld%lld",&n,&m,&k))
    {
        if(k==-1 && ((n%2)^(m%2))==1)
        {
            printf("Orz\n");
        }else{
            printf("O(^_^)O~~\n");
        }
    }
    return 0;
}
