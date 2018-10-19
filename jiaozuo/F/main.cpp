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


/************************************************************/

const int MAXN = 1009;
const int MAXM = 100009;
struct Edge{
	int to,next,cap,flow,cost;
	Edge(int _to = 0,int _next = 0,int _cap = 0,int _flow = 0,int
			_cost = 0):
		to(_to),next(_next),cap(_cap),flow(_flow),cost(_cost){}
}edge[MAXM];
struct ZKW_MinCostMaxFlow{
	int head[MAXN],tot;
	int cur[MAXN];
	int dis[MAXN];
	bool vis[MAXN];
	int ss,tt,N;
	int min_cost, max_flow;
	void init() {
		tot = 0;
		memset(head, -1,sizeof(head));
	}
	void addedge(int u,int v,int cap,int cost){
		edge[tot] = Edge(v,head[u],cap,0,cost);
		head[u] = tot++;
		edge[tot] = Edge(u,head[v],0,0, -cost);
		head[v] = tot++;
		//cout<<u<<" "<<v<<" "<<cost<<endl;
	}
	int aug(int u,int flow){
		if(u == tt)return flow;
		vis[u] = true;
		for(int i = cur[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			if(edge[i].cap > edge[i].flow && !vis[v] && dis[u] ==
					dis[v] + edge[i].cost){
				int tmp = aug(v,min(flow,edge[i].cap -edge[i].flow))
					;
				edge[i].flow += tmp;
				edge[i^1].flow -= tmp;
				cur[u] = i;
				if(tmp)return tmp;
			}
		}
		return 0;
	}
	bool modify_label(){
		int d = INF;
		for(int u = 0;u < N;u++)
			if(vis[u])
				for(int i = head[u];i != -1;i = edge[i].next){
					int v = edge[i].to;
					if(edge[i].cap>edge[i].flow && !vis[v])
						d = min(d,dis[v]+edge[i].cost - dis[u]);
				}
		if(d == INF)return false;
		for(int i = 0;i < N;i++)
			if(vis[i]){
				vis[i] = false;
				dis[i] += d;
			}
		return true;
	}

	pair<int,int> mincostmaxflow(int start,int end,int n){
		ss = start, tt = end, N = n;
		min_cost = max_flow = 0;
		for(int i = 0;i < n;i++)dis[i] = 0;
		while(1){
			for(int i = 0;i < n;i++)cur[i] = head[i];
			while(1){
				for(int i = 0;i < n;i++)vis[i] = false;
				int tmp = aug(ss,INF);
				if(tmp == 0)break;
				max_flow += tmp;
				min_cost += tmp*dis[ss];
			}
			if(!modify_label())break;
		}
		return make_pair(min_cost,max_flow);
	}
	void debug()
	{
        for(int u = 0;u < 1;u++)
            for(int i = head[u];i != -1;i = edge[i].next){
                int v = edge[i].to;
                printf("%d %d:%d\n",u,v,edge[i].cost);
            }
	}
}solve;
/************************************************************/

int T, n, k, m, start, en, l[N], r[N], x[N];

/************************************************************/

const int MAXSIZE = 50000007;
char buf[MAXSIZE];
ll bufpos;

void init1(){
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}

inline int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
/************************************************************/

struct node{
    int l,r,x;
}s[300];
bool vis[300];
bool cmp(const node &a,const node &b)
{
    return a.r<b.r;
}
int main(void) {
	//if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
//	init1();
//	T = readint();
	scanf("%d", &T);
	while(T--) {
//		n = readint();
//		k = readint();
//		m = readint();
		scanf("%d%d%d", &n, &k, &m);
		for(int i = 1; i <= m; i++) {
//			s[i].l = readint();
//			s[i].r = readint();
//			s[i].x = readint();
			scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].x);
		}
		start = 0, en = 1 + 2 * m + 1;
		solve.init();
		solve.addedge(start, 1, k, 0);
		for(int i = 1; i <= m; i++) {
			solve.addedge(1, 1 + i, 1, 0);
		}
        sort(s+1,s+m+1,cmp);
		for(int i = 1; i <= m; i++) {
			for(int j = i + 1; j <= m; j++) {
				if(i == j) continue;
				if(s[i].r < s[j].l) {
					solve.addedge(1 + m + i, 1 + j, 1, 0);
					//addedge(1 + m + j, 1 + i, 1, 0);
				}
				else if(s[j].r < s[i].l)
					solve.addedge(1 + m + j, 1 + i, 1, 0);
//                if(s[j].l>s[i].r)
//                {
//                    solve.addedge(1+m+i,1+j,1,0);//,cout<<i<<" "<<j<<endl;
//                    break;
//                }
			}
		}
		for(int i = 1; i <= m; i++) {
			solve.addedge(1 + i, 1 + m + i, 1, -s[i].x);
			solve.addedge(1 + m + i, en, 1, 0);
		}
		//solve.debug();
		pii ans = solve.mincostmaxflow(start, en, en + 1);
		printf("%d\n", -ans.x);
	}

	return 0;
}
/*
4
10 1 3
1 2 2
2 3 4
3 4 8

10 1 3
1 3 2
2 3 4
3 4 8

100000 1 3
1 100000 100000
1 150 301
100 200 300

100000 2 3
1 100000 100000
1 150 301
100 200 300


*/
