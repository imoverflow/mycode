#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[2][1000000];
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[0][i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[1][i]);
    }

    return 0;
}
