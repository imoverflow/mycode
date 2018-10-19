#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    if(m==1)
    {
        printf("%I64d",n);
    }else{
        int cnt=0;
        while(n)
        {
            cnt++;
            n/=2;
        }
        printf("%I64d",((long long)1<<cnt)-1);
    }
    return 0;
}
