#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[100000]={0,1};
int main()
{
    for(int i=2;i<100;i++)
    {
        s[i]=(3*s[i-1]-s[i-2])/2+i+1;
    }
    for(int i=0;i<100;i++)
    {
        printf("%lld\n",s[i]);
    }
    return 0;
}
