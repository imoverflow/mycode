#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
const int N = 1e6+5;

int main()
{
//	freopen("powers.in", "r", stdin);
	int t;	scanf("%d", &t);
	while(t--)
	{
		int n, b, k;
		scanf("%d", &n);
		int ans = 1;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d", &b, &k);
			if(b&1)
			{
				if(k&1)	ans *= -1;
			}
			else
			{
				k %= b+1;
				if(k==b)	ans *= -1;
				else if(k&1)	ans *= -1;
			}
		}
		if(ans==-1)	puts("1");
		else puts("2");
	}
	return 0;
}
