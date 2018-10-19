#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long res=0;
    char b;
    long long a;
    while(~scanf("%lld%c",&a,&b))
    {
        res^=a;
        if(b=='\n')
            break;
    }
    printf("%lld\n",res);
    return 0;
}
