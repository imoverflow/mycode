#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#define MM(a,b) memset(a,b,sizeof(a));
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define CT continue
#define SC scanf
const int N=1e6+10;
const int mod=1e9+7;
int cas,n,m,k,kk;
ll C[N],inv[N];

ll _pow(ll a,ll b)
{
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

void  init_yuan()
{
   inv[1]=1;
   for(int i=2;i<=1e6;i++){
       inv[i]=(mod-mod/i)*inv[mod%i]%mod;
   }
}//求逆元模板

void init_cki()
{
    C[0]=1;
    for(int i=0;i<k;i++){
        C[i+1]=C[i]*(k-i)%mod*inv[i+1]%mod;
    }
}//预处理C(k,i)

ll c(ll m,ll k)
{
    ll res=1;
    k=min(k,m-k);
    for(int i=0;i<k;i++){
        res=res*(m-i)%mod;
    }
    for(int i=0;i<k;i++){
        res=res*inv[i+1]%mod;
    }
    return res;
}//求C（m,k）

int main()
{
    init_yuan();
    init_cki();
//    int t;
//    scanf("%d",&t);
//    int cnt=1;
//    while(t--)
//    {
//        long long n,m,k;
//        scanf("%lld%lld%lld",&n,&m,&k);
//        long long ans=(((  (k*_pow(k-1,n-1))%mod*c(m,k)- ((k-1)*_pow(k-2,n-1=))%mod*c(m,k-1) )%mod))%mod;
//        printf("Case #%d: %lld\n",cnt++,ans);
//    }
    for(int i=1;i<1000;i++)
    {
        for(int j=i;j<1000;j++)
        {
            printf("%d %d %lld\n",i,j,c(j,i));
        }
    }
}
