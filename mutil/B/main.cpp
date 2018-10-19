#include <iostream>
#include <bits/stdc++.h>
#define MOD 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;

int prime[MAXN];
bool is_prime[MAXN];
int sieve(ll n)                                 /**筛法打表，用线筛时间上也差不多**/
{                                               /**筛1e6就足够了，因为r最大就1e12**/
    ll p=0;
    for(ll i=0;i<=n;i++)
    {
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    }
    return p;
}
ll a[MAXN];               /**a数组记录数字，b数组记录(kc1+1)(kc2+1)……(kck+1)的乘积**/
ll b[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    int v=sieve(1000001);
    while(t--)
    {
        ll l,r,k,sum=0;
        scanf("%lld%lld%lld",&l,&r,&k);
        for(ll i=l;i<=r;i++)
        {
            a[i-l]=i;
            b[i-l]=1;
        }
        for(ll i=0;prime[i]*prime[i]<=r&&i<v;i++)
        {
            ll x=l-l%prime[i];
            while(x<l) x+=prime[i];
            for(ll j=x;j<=r;j+=prime[i])
            {
                int cnt=0;
                while(a[j-l]%prime[i]==0)
                {
                    cnt++;
                    a[j-l]/=prime[i];
                }
                b[j-l]=(b[j-l]*(k*cnt+1))%MOD;
            }
        }
        for(ll i=l;i<=r;i++)
        {
            if(a[i-l]!=1) b[i-l]=b[i-l]*(k+1)%MOD;         /**a[i-l]!=1意味着筛不走的质数**/
        }
        for(ll i=l;i<=r;i++)
        {
            sum+=b[i-l]%MOD;
        }
        printf("%lld\n",sum%MOD);
    }
    return 0;
}
