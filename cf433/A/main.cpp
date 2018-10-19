#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=n/2;i>=0;i--)
    {
        if(__gcd(i,n-i)==1)
        {
            printf("%d %d",i,n-i);
            break;
        }
    }
    return 0;
}
