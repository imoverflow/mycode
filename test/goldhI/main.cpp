#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=1;
        for(int i=2;i<n;i++)
        {
            if(__gcd(n,i)==1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
