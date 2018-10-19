#include<bits/stdc++.h>
#define x first
#define y second
#define P(a,b) pair<a,b>
#define V(int)  vector<int>
#define M(a, b) map<a, b>
#define Q(a)    queue<a>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long mod = 1e9+7;
const double eps = 1e-9;
const int N = 5+2e3;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll dp[N];

ll qpow(ll a, ll b)
{
    ll  x = 1;
    while(b)
    {
        if(b&1) x *= a;
        x %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return x;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x = 1;  y = 0;
        return a;
    }
    ll d = exgcd(b, a%b, x, y);
    ll t = x;
    x = y, y = t - a/b*y;
    return d;
}

ll mod_inv(ll a, ll m)
{
    ll x, y;
    exgcd(a, m, x, y);
    return (m+x%m)%m;
}

ll A(ll x)
{
    ll ans = 1;
    while(x)
    {
        ans = ans*x;
        x --;
        ans %= mod;
    }
    return ans;
}

ll C(ll n, ll m)
{
    ll x1 = A(n);
    ll x2 = A(m-n);
    ll y = A(m);
    return (((y*mod_inv(x2, mod))%mod)*mod_inv(x1, mod))%mod;
}

int main()
{
//    freopen("C:\\Users\\admin\\Desktop\\Debug\\1.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, 0, sizeof dp);
        ll ans = 1, n, m;
        dp[1] = 1;
        cin>>n>>m;
        for(ll i = 2; i<= n&&i<m; i ++)
        {
            dp[i] = qpow(i, n) - ans*i;
            dp[i] = (dp[i]%mod + mod)%mod;
            ans += dp[i];
            ans %= mod;
        }
        ll pt = 0;
        for(ll i = 1; i <= n&&i < m; i ++)
        {
            ll res = C(i, m);
//            cout<<res<<endl;
            pt += ((res * dp[i])%mod)*(qpow(m-i, n)%mod);
            pt %= mod;
        }
        cout << pt<<endl;
    }
    return 0;
}
