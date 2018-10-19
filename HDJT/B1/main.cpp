#include <bits/stdc++.h>
const int N =  2e5+50;
using namespace std;
int a[N];
int main()
{
    int tt;	scanf("%d", &tt);
    while(tt--)
	{
		int n, q;	scanf("%d%d", &n, &q);
		int pos = 1, odd = 0, even = 0;
		for(int i = 0; i < q; i ++)
		{
			int x, y;
			scanf("%d", &x);
			if(x==1)
			{
				scanf("%d",  &y);
				odd += y;
				even += y;
				pos += y;
				pos%=2;
			}
			else
			{
				if(pos)	odd++, even--;
				else 	odd--, even++;
				pos = 1-pos;
			}
			odd %= n;
			even %= n;
		}
		for(int i = 0; i < n; i ++)
		{
			int x;
			if(i&1)
				x = ((i+even)%n+n)%n;
			else
				x = ((i+odd)%n+n)%n;
			a[x] = i+1;
		}
		for(int i = 0; i < n; i ++)
		{
			if(i)	printf(" ");
			printf("%d", a[i]);
		}
		puts("");
	}
    return 0;
}
