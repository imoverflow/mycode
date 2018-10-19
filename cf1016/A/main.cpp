#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[1000006];
int main()
{
    int n,m;
    cin>>n>>m;
    long long res=0;
    long long pre=0;
    for(int i=0;i<n;i++)
    {
        pre=res;
        scanf("%lld",&s[i]);
        res+=s[i];
        printf("%lld ",res/m-pre/m);
    }

    return 0;
}
