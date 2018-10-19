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

ll a, b, c, d, vv, t;
int T;

vector<pll> v;

int main(void) {
	if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &vv, &t);
		ll up = a / __gcd(a, c) * c;
		ll t1 = 0, t2 = 0;
		v.clear();
		while(t1 <= up && t2 <= up) {
			if(t1 <= t2) {
				v.push_back(pll(t1, 1));
				t1 += a;
			}
			else {
				v.push_back(pll(t2, 2));
				t2 += c;
			}
		}
		while(t1 <= up) {
			v.push_back(pll(t1, 1));
			t1 += a;
		}
		while(t2 <= up) {
			v.push_back(pll(t2, 2));
			t2 += c;
		}
		ll ans = 0, pre;
		for(auto i: v) {
			if(i.x == up) break;
			//cout << i.x << " " << i.y << endl;
			if(i.x == 0 && i.y == 1) {
				ans += b - 1;
			}
			else if(i.x == 0 && i.y == 2) {
				ans += d;
			}
			else if(pre + vv >= i.x) {
				if(i.y == 1)
					ans += b;
				else
					ans += d;
			}
			else {
				if(i.y == 1)
					ans += b - 1;
				else
					ans += d - 1;
			}
			pre = i.x;
		}
		pre = max(-a, -c);
		if(t < up)
			ans = 0;
		else {
			if(pre + vv >= 0) {
				ll t1 = ans + 1;
				ans += t1 * (t / up - 1);
				t %= up;
			}
			else {
				ll t1 = ans;
				ans += t1 * (t / up - 1);
				t %= up;
			}
		}
		//cout << ans << endl;
		for(auto i: v) {
			//int tt = ans;
			if(i.x > t) break;
			if(i.x == 0 && i.y == 1) {
				if(pre + vv >= i.x && ans) {
					ans += b;
				}
				else
					ans += b - 1;
			}
			else if(i.x == 0 && i.y == 2) {
				ans += d;
			}
			else if(pre + vv >= i.x) {
				if(i.y == 1)
					ans += b;
				else
					ans += d;
			}
			else {
				if(i.y == 1)
					ans += b - 1;
				else
					ans += d - 1;
			}
			pre = i.x;
			//cout << i.x << " " << i.y << endl;
			//cout << ans - tt << endl;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
