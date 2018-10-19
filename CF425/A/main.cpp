#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    if((n/k)%2)
    {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
