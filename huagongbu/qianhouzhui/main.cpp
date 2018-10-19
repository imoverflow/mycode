#include<bits/stdc++.h>
#define x first
#define y second
#define ok cout << "ok" << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=3e5+9;
const int shift=1e3+9;
const double Eps=1e-7;

int nex[N], n, x, y, q;
string s[N];
map<pii, int> vis, m;

void getNex(string &s) {
	nex[0] = -1;
	int k = -1;
	int j = 0;
	int len = s.length();
	while(j < len) {
		if(k == -1 || s[j] == s[k]) {
			k++;
			j++;
			nex[j] = k;
		}
		else
			k = nex[k];
	}
}

int main(void) {
	if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			cin >> s[i];
		cin >> q;
		for(int i = 0; i < q; i++) {
			cin >> x >> y;
			if(x == y) {
				cout << s[x-1].length() << endl;
				continue;
			}
			//if(x > y) swap(x, y);
			if(vis[pii(x, y)]) {
				cout << m[pii(x, y)] << endl;
				continue;
			}
			vis[pii(x, y)] = 1;
			string t = s[y-1] + '#' + s[x-1];
			getNex(t);
			//cout << t << endl;
			//for(int i = 0; i < t.length(); i++)
			//	printf("%d: %d\n", i, nex[i]);
			int ans = nex[t.length()];
			m[pii(x, y)] = ans;
			cout << ans << endl;
		}
	}

	return 0;
}
