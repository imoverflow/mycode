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

int v[29][29], n, d, flag[29];

vi ans;

int main(void){
	freopen("in.txt","r",stdin);
	int T; cin>>T;
	while(T--){
		ans.clear();
		memset(v, 0, sizeof v);
		cin>>n;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin>>d;
				v[i][j]=d;	//i give j d.
			}
		}
		for(int i=1; i<=n; i++){
			int t=0;
			for(int j=1; j<=n; j++)
				t-=v[i][j];
			if(t>=0) continue;		//?
			memset(flag, 0, sizeof flag);
			flag[i]=1;
			bool change=1;
			while(change){
				change=0;
				for(int j=1; j<=n; j++){
					if(flag[j]) continue;
					int sum=0;
					for(int k=1; k<=n; k++){
						if(flag[k]) continue;
						sum-=v[j][k];
					}
					//printf("%d, %d: %d\n", i, j, sum);
					if(sum<0){
						flag[j]=1;
						change=1;
						break;
					}
				}
				//change=0;
			}
			int cnt=0, t1=INF;
			for(int i=1; i<=n; i++){
				if(flag[i])
					cnt++;
				else
					t1=i;
			}
			if(cnt==n-1){
				//printf("%d: %d\n", i, t1);
				ans.push_back(t1);
			}
		}
		set<int> se;
		for(int i=0; i<ans.size(); i++)
			se.insert(ans[i]);

	//	sort(ans.begin(), ans.end());
		if(ans.size()==0){
			printf("0\n");
			continue;
		}
		int first=1;
		for(set<int>::iterator it=se.begin(); it!=se.end(); it++){
			if(first){
				printf("%d", *it);
				first=0;
			}
			else
				printf(" %d", *it);
		}
		printf("\n");
	//	for(int i=0; i<ans.size(); i++)
	//		printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
	}

	return 0;
}
