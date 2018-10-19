#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P; //¡¡end , begin
const int N = 150000 + 9;

char s[N], ma;
int n, to[N];
bool be[N], vis[N];

void init() {
	memset(be, true, sizeof be);
	memset(vis, false, sizeof vis);
	ma = '0';
}

void build(int n) {
	for (long long i = 0; i < n; i++) {
		to[i] = (i * i + 1) % n;
	}
}

void out(int u, int times) {
	putchar(s[u]);
	if (times) out(to[u], times - 1);
}

void solve() {
	scanf ("%d%s", &n, s);
	init();
	build(n);
	for (int i = 0; i < n; i++) {
		ma = max (ma, s[i]);
	}
	queue<P> p, q;
	for (int i = 0; i < n; i++) {
		if (s[i] == ma) {
			q.push(P(i, i));
		}
	}
	while (q.size() > 1) {
		ma = '0';
		while (!q.empty()) {
			P t = q.front();	q.pop();
			t.fi = to[t.fi];
			if (t.fi == t.se) {
				out(t.fi, n - 1);
				puts("");
				return ;
			}
			if (vis[t.fi]) continue;
			be[t.fi] = false; // cant be begin
			vis[t.fi] = true; // visited
			p.push(t);
			ma = max(ma, s[t.fi]);
		}
		while (!p.empty()) {
			P t = p.front();	p.pop();
			if (s[t.fi] == ma && be[t.se]) {
				q.push(t);
			}
		}
	}
	P t = q.front();
	out(t.se, n - 1);
	puts("");
}

int main()
{
//	freopen ("1.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		printf ("Case #%d: ", ca);
		solve();
	}

    return 0;
}
