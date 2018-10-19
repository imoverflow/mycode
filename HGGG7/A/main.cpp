#include<bits/stdc++.h>
#define x first
#define y second
#define bug puts("bug..........................");
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+9;
const int shift=1e3+9;
const double Eps=1e-7;

int n, m, vis[509][509], a[509][509], ans[509][509], sx, sy;

struct node{
	int x;
	pii y;
	node(int x, pii y): x(x), y(y) {}
	bool operator < (const node & b) const {
		return x>b.x;
	}
};

void bfs(){
	memset(ans, 0, sizeof ans);
	ans[sx][sy]=a[sx][sy];
	//printf("%d\n", ans[sx][sy]);
	priority_queue<node> que;
	que.push(node(a[sx][sy], pii(sx, sy)));
	//printf("t: %d %d\n", sx, sy);
	vis[sx][sy]=1;
	while(!que.empty()){
		node t=que.top();
		pii p=t.y;
		que.pop();
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(i==0 && j==0) continue;
				int nx=p.x+i, ny=p.y+j;
				if(1<=nx && nx<=n && 1<=ny && ny<=m && a[nx][ny]<0 && !vis[nx][ny]) {
					//printf("%d %d\n", nx, ny);
					vis[nx][ny]=1;
					ans[nx][ny]=max(a[nx][ny], t.x);
					que.push(node(ans[nx][ny], pii(nx, ny)));
				}
			}
		}
	}
	int anss=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			//printf("%d ", ans[i][j]);
			anss+=ans[i][j];
		}
		//printf("\n");
	}
	printf("%d\n", -anss);
}

int main(void){
	//if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	while(cin>>n>>m){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++)
				scanf("%d", &a[i][j]);
		}
		cin>>sx>>sy;
		bfs();
	}

	return 0;
}
