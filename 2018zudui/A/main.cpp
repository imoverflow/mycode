#include<bits/stdc++.h>
#define x first
#define y second
#define ok puts("ok");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+9;
const int shift=1e3+9;
const double Eps=1e-7;

int n, m, d, b[N], vis[N];
vi v[N], g[N];
vector<pii> ans;

int main(void) {
	if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	while(cin >> n) {
		memset(b, 0, sizeof b);
		memset(vis, 0, sizeof vis);
		ans.clear();
		for(int i = 1; i <= n; i++)
			v[i].clear();
		for(int i = 1; i <= n; i++) {
			scanf("%d", &m);
			for(int j = 0; j < m; j++) {
				scanf("%d", &d);
				v[d].push_back(i);   //zisun
				b[i]++; //shuliang
			}
		}
		queue<int> que;
		for(int i = 1; i <= n; i++)
			if(b[i] == 0)
				que.push(i);
		while(que.size()) {
			int u = que.front();
			que.pop();
			for(int i = 0; i < v[u].size(); i++) {
				int fa = v[u][i];
				g[fa].push_back(u);
				b[fa]--;
				if(b[fa] == 0) {
					que.push(fa);
					for(int j = 0; j <g[fa].size(); j++) {
						int t = g[fa][j];
						if(!vis[t]) {
							ans.push_back(pii(fa, t));
							vis[t] = 1;
						}
					}
				}
			}
		}
		if(ans.size() == n-1) {
			printf("YES\n");
			for(int i = 0; i < ans.size(); i++)
				printf("%d %d\n", ans[i].x, ans[i].y);
		}
		else
			printf("NO\n");
	}

	return 0;
}
