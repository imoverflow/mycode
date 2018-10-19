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

int n;
string s;

void solve(){
	double ans=0;
	cin>>s;
	int len=s.length(), cnt=0, l=0, turn[1009], dot=0, sub=0, add=0, num=0;
	stringstream data(s);
	turn[0]=1;
	char sep;
	for(int i=0; i<len; i++){
		if('0'<=s[i] && s[i]<='9' && i==len-1){
			num=1;
			int t=1;
			for(int j=0; j<=cnt; j++)
				t*=turn[j];
			double t1;
			data>>t1;
		//printf("%.6f\n", t1);
			//printf("%d %d\n", l, i);
			if(dot)
				ans+=t*t1, dot=0;
			else
				ans+=t*t1;
			num=0;
			//printf("%.6f\n", ans);
		}
		else if(('0'<=s[i] && s[i]<='9') || s[i]=='.'){
			num=1;
			if(s[i]=='.')
				dot=1;
		}
		else{
			if(num){
				int t=1;
				for(int j=0; j<=cnt; j++){
					//printf("turn[%d]:%d\n", j, turn[j]);
					t*=turn[j];
				}
				double t1;
				data>>t1;
			//printf("%.6f\n", t1);
				if(dot)
					ans+=t*t1, dot=0;
				else
					ans+=t*t1;
				num=0;
			}
			data>>sep;
			if(s[i]=='-')
				turn[cnt]=-1;
			else if(s[i]=='('){
				cnt++;
				turn[cnt]=1;
			}
			else if(s[i]==')')
				cnt--;
			else if(s[i]=='+')
				turn[cnt]=1;
		}
	}
	printf("%.6f\n", ans);
}

int main(void){
	//freopen("in", "r", stdin); freopen("out", "w", stdout);
	//string::size_type st;
	//string t="123.4567+999.3";
	//float mars = std::stof (t,&st);
	//printf("%f\n", stof(t.substr(st)));
	while(cin>>n)
		solve();


	return 0;
}
