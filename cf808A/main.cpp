#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long powa(long long a,long long b){
    long long ans=1;
    for(long long i=0;i<b;i++)
    {
        ans*=a;
    }
    return ans;
}
int main()
{
    long long n,big,cnt=0;
    cin>>n;
    long long m=n;
    if(n<=9) puts("1");
    else
    {
        while(n>0){
            big=n%10;
            n/=10;
            cnt++;
        }
        printf("%lld\n",(big+1)*powa(10,cnt-1)-m);
    }
    return 0;
}
