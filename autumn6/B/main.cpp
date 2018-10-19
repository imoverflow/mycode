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

int n, l;
string s, t, st;
vector<string> v[1009];
map<string, int> m;

void dfs(string d){
	if(v[m[d]].size()==1){
		d=v[m[d]][0];
		//cout<<"t: "<< d<<endl;
		for(int i=0; i<d.length(); i++){
			if(d[i] == st[l])
				l++;
		}
		return;
	}
	int u=m[d];
	for(int i=0; i<v[u].size(); i++){
		dfs(v[u][i]);
	}
}

int main(void){
	//if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	int T; cin>>T;
	while(T--){
		for(int i=0; i<=1000; i++)
			v[i].clear();
		m.clear();
		cin>>n;
		int all=0;
		getchar();
		for(int i=0; i<n; i++) {
			getline(cin, s);
			//cout<<s<<endl;
			int flag=0;
			for(int i=0; i<s.length(); i++)
				if(s[i]=='+')
					flag=1;
			if(flag){
				int cnt=0;
				string t[3];
				for(int i=0; i<s.length(); i++){
					if(s[i] == ' ') continue;
					if(s[i]!=' ' && s[i]!='+' && s[i]!='='){
						string t1=s.substr(i, 1);
						t[cnt]+=t1;
					}
					else
						cnt++;
				}
				for(int i=0; i<3; i++){
					//cout<<t[i]<<endl;
					m[t[i]]=all++;
				}
				v[m[t[0]]].push_back(t[1]);
				v[m[t[0]]].push_back(t[2]);
			}
			else{
				int cnt=0;
				string t[2];
				for(int i=0; i<s.length(); i++){
					if(s[i] == ' ') continue;
					if(s[i]!=' ' && s[i]!='+' && s[i]!='='){
						string t1=s.substr(i, 1);
						t[cnt]+=t1;
						//t[cnt]+=s[i];
					}
					else
						cnt++;
				}
				for(int i=0; i<2; i++)
					m[t[i]]=all++;
				v[m[t[0]]].push_back(t[1]);
			}
		}
		cin>>t;
		cin>>st;
	//	cout<<t<<endl;
	//	cout<<st<<endl;
		l=0;
		dfs(t);
		//printf("l: %d\n", l);
		if(l==st.length())
			printf("YES\n");
		else
			printf("NO\n");
	}



	return 0;
}
