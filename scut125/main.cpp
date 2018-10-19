#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
const int N=1e5+9;

bool vis[5009][5009];
int n, a[5009];
char s[5009];

bool check(int p, int q){
	while(p<q)
		if(s[p++]!=s[q--])
			return false;
	return true;
}

int main(void){
//	freopen("in.txt","r",stdin);
//	freopen("stout.txt","w",stdout);
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i+1);
		scanf("%s", s);
		ll dp[5009];
		memset(dp, 0, sizeof dp);
		int len=strlen(s);
		for(int i=0; i<len; i++){
			for(int j=i; j<len; j++){
				if(check(i, j))
					vis[i][j]=1;
				else
					vis[i][j]=0;
			}
		}
		for(int i=0; i<len; i++){
			for(int j=1; j<=n && i+j<=len; j++){
				if(vis[i][i+j-1]){
					dp[i+j]=max(dp[i+j], dp[i]+a[j]);
				}
			}
		}
		printf("%lld\n", dp[len]);
	}
	return 0;
}
