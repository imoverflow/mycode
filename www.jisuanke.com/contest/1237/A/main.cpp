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

vi G[N];
int n, m, u, v, vis[N], dis[N], fa[N];
bool flag;

bool bfs(int uu) {
	vis[uu] = 1;
	queue<int> que;
	que.push(uu);
	while(que.size()) {
		int u = que.front();
		que.pop();
		for(int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				fa[v] = u;
				que.push(v);
			}
			else if(dis[v] == dis[u] && fa[u] == fa[v]){
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		flag = false;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && bfs(i)) {
				flag = true;
				break;
			}
		}
		if(flag)
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}
