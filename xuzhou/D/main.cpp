#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int prime[N], cnt, u[N];
bool vis[N];

void init()
{
    memset(vis, 0, sizeof vis);
    cnt = 0;
    u[1] = 1;
    for(int i = 2; i < N; i ++)
    {
        if(!vis[i])
        {
            u[i] = -1;
            prime[cnt ++] = i;
        }
        for(int j = 0, k; j < cnt && (k = i * prime[j]) < N; j ++)
        {
            vis[k] = 1;
            if(i % prime[j])
                u[k] = -u[i];
            else
            {
                u[k] = 0;
                break;
            }
        }
    }
}

int main()
{
    init();
    ll n, m;
    cin >> m >> n;
    ll p = 1;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < cnt && n > 1; i ++)
    {
        if(n % prime[i] == 0)
        {
            p *= -1;
            int num = 0;
            vis[prime[i]] = 1;
            while(n % prime[i] == 0)
            {
                n /= prime[i];
                num ++;
            }
            if(num > 1) p = 0;
        }
    }

    vector<int> v;
    for(int i = 0; i < cnt && m > 1; i ++)
    {
        if(m % prime[i] == 0)
        {
            if(!vis[prime[i]])
                v.push_back(prime[i]);
            while(m % prime[i] == 0)
                m /= prime[i];
        }
    }
    if(m != 1 && m != n)    v.push_back(m);
    ll ans = 0;
    for(int i = 0, sz = v.size(); i < 1 << (sz); i ++)
    {
        int j = i, num = 0;
        while(j)
        {
            if(j & 1)   num ++;
            j >>= 1;
        }
        if(num & 1) ans -= p;
        else        ans += p;
    }
    cout << ans << endl;
    return 0;
}
