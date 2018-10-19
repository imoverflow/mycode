#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[1000006];
long long k;
long long rev(long long a,int &n){
    n=0;
    long long sum=0;
    while(a!=0)
    {
        s[n++]=a%10;
        a/=10;
    }
    for(long long j=1,i=n-1;i>=0;i--,j*=10)
    {
        sum+=s[i]*j%k;
    }
    return sum%k;
}
long long po[20];
void powa()
{
    int ans=1;
    po[0]=1;
    for(int i=1;i<18;i++)
    {
        po[i]=po[i-1]*10;
    }
}
int main()
{
    long long n;
    powa();
    scanf("%I64d%I64d",&n,&k);
    long long sum=0;
    int x;
    for(long long j=10,i=1;i<=n;i++)
    {
        sum+=rev(i,x)%k;
        sum+=i*po[x]%k;
    }
    printf("%I64d\n",sum%k);
    return 0;
}
