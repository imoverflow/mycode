#include<bits/stdc++.h>
#define x first
#define y second
#define ok cout << "ok" << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const long double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = 9223372036854775807;
const double Eps = 1e-7;
const int N = 1e5+9;

char s[N];
int T;

int main(void) {
//    freopen("1.txt", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		ll a, b, c, d, v, t, ans = 0, res = 0;
		cin >> a >> b >> c >> d >> v >> t;
		if(v >= a || v >= c)
        {
            cout << t / a * b + b + t / c * d + d - 1 << endl;
            continue ;
        }
		for(ll i = 0; i < a; i ++)
        {
            ll t = i * c % a;
            if(t <= v || t >= a - v )
                res ++;
            res += d - 1;
        }
        res += c * (b - 1);
        ans = res * (t / a / c);
        t %= a * c;

        ans += (t / a + 1) * (b - 1);
        ans += (t / c + 1) * (d - 1);

        ll pa = 0, pc = 0;
        while(pa <= t && pc <= t)
        {
            if(abs(pa - pc) <= v)    ans ++;
            if(pa + a > t)      pc += c;
            else if(pc + c > t) pa += a;
            else if(pa < pc)    pa += a;
            else                pc += c;
        }
        cout << ans << endl;
	}

	return 0;
}

/*100
1 1000000 1 1000000 2 1000000000000
1999999000002000000
10000 1000000 9999 1000000 2 1000000000000
200009803040004
1000000 1000000 999999 1000000 2 1000000000000
2000001000004

2 1 1 3 1 1 4

*/
