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

string s[109];
int n;
bool cmp(const string &a,const string &b)
{
//    int len=min(a.length(),b.length());
//    for(int i=0;i<len;i++)
//    {
//        if(a[i]!=b[i])
//        {
//            return a[i]<b[i];
//        }
//    }
//    if(a[len]=='\0')
//    {
//        int p=0;
//        while(a[p%a.length()]==b[len+p]&&p+len<b.length())
//        {
//            p++;
//        }
//        return a[p]<b[len+p];
//    }else{
//        int p=0;
//        while(a[len+p]==b[p%b.length()]&&p+len<a.length())
//        {
//            p++;
//        }
//        return a[len+p]<b[p];
//    }
    return a+b<b+a;
}
int main(void){
	//if(fopen("in", "r")!=NULL) {freopen("in", "r", stdin); freopen("out", "w", stdout);}
	while(cin>>n){
		for(int i=0; i<n; i++)
			cin>>s[i];
		sort(s, s+n,cmp);
		for(int i=0; i<n; i++)
			cout<<s[i];
		printf("\n");
	}

	return 0;
}
