#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;
int n;

ll solve()
{
    if(n&1) return (1ll*n*n-3)/2;
    else return 1ll*n*n/2-1;
}

int main()
{
    while(~scanf("%d",&n))
        printf("%lld\n",solve());
    return 0;
}
