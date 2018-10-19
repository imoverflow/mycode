#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn=1000006;
long long phi[maxn],miu[maxn],fac[maxn];
long long f[maxn];
long long F[maxn];
void init()
{
    for(int i=1;i<maxn;++i) fac[i]=i;
    phi[1]=miu[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(fac[i]==i)
            for(int j=i<<1;j<maxn;j+=i)
                fac[j]=i;
        if(i/fac[i]%fac[i]) phi[i]=(fac[i]-1)*phi[i/fac[i]],miu[i]=-miu[i/fac[i]];
        else phi[i]=fac[i]*phi[i/fac[i]],miu[i]=0;
    }
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)    return (x=1,y=0,a);
    if(a==0)    return (x=0,y=1,b);
    long long r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
int mul_1(long long a,long long b)
{
    long long x,y;
    exgcd(a,b,x,y);
    x%=b;
    while(x<0)  x+=b;
    return x;
}

int main()
{
    int t;
    scanf("%d",&t);
    init();
    long long ans;
    while(t--)
    {
        long long n,m,p;
        scanf("%lld%lld%lld",&n,&m,&p);
        int x=min(n,m);
        memset(f,0,sizeof(long long)*(x+1));
//        memset(F,0,sizeof(long long)*(x+1));
        ans=0;
//        for(int i=1;i<=x;i++)
//            F[i]=1ll*(m/i)*(n/i);
        for(int i=1;i<=x;i++)
        {
            for(int j=i;j<=x;j+=i)
            {
                f[i]+=miu[j/i]*(m/j)*(n/j);
//                f[i]+=miu[j/i]*F[j];
            }
        }
        for(int i=1;i<=x;i++)
        {
            f[i]%=p;
            ans=(ans+1ll*i*mul_1(phi[i],p)%p*f[i])%p;
        }
        while(ans<0) ans+=p;
        printf("%lld\n",ans);
    }
    return 0;
}
