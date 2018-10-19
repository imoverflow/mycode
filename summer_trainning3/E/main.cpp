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

int a[N], d, flag, n, lp, rp, buff;
vector<char> v;

void func(){
	for(int i=lp; i<rp; i++){
		if(a[i]==a[i+1])
			a[i+1]*=2, lp++;
		else
			break;
	}
	for(int i=rp; i>lp; i--){
		if(a[i]==a[i-1])
			a[i-1]*=2, rp--;
		else
			break;
	}
}

void func1(){
	if(lp==rp){
		v.push_back('r');
		a[++rp]=d;
		return;
	}
	int flag1=1;
	for(int i=lp; i<rp; i++)
		if(a[i]>a[i+1])
			flag1=0;
	if(flag1){
		a[++rp]=d;
		v.push_back('r');
		return;
	}
	flag1=1;
	for(int i=lp; i<rp; i++)
		if(a[i]<a[i+1])
			flag1=0;
	if(flag1){
		a[--lp]=d;
		v.push_back('L');
		return;
	}
	flag=0;
}

int main(void){
	//freopen("in", "r", stdin); freopen("out", "w", stdout);
	int T; cin>>T;
	while(T--){
		buff=3009, flag=1, lp=rp=buff;
		v.clear();
		cin>>n;
		cin>>a[buff];
		v.push_back('r');
	//	for(int i=lp; i<=rp; i++)
	//		printf("%d\n", a[i]);
		for(int i=1; i<n; i++){
			scanf("%d", &d);
			//printf("%d\n", d);
			if(d>a[lp] && d>a[rp]){
				func1();
			}
			else if(d>a[lp]){
				a[++rp]=d;
				v.push_back('r');
			}
			else if(d>a[rp]){
				a[--lp]=d;
				v.push_back('l');
			}
			else if(abs(d-a[lp]) < abs(d-a[rp])){
				a[--lp]=d;
				v.push_back('l');
			}
			else{
				a[++rp]=d;
				v.push_back('r');
			}
			func();
//			printf("%d: \n", i);
//		for(int i=lp; i<=rp; i++)
//			printf("%d\n", a[i]);
//		printf("\n");
		}
		if(lp!=rp)
			flag=0;
		if(flag)
			for(int i=0; i<v.size(); i++)
				printf("%c", v[i]);
		else
			printf("no");
		printf("\n");
	}

	return 0;
}
