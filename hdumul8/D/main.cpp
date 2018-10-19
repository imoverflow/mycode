#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define io ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int N = 3e2+10;

char a[N][N];

int main()
{
    int T;     cin >> T;
    while(T --)
    {
        int n, m;
        cin >> n >> m;
        memset(a,  0, sizeof a);
        if(n % 2 && m % 2)
        {
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < m; j ++)
                    putchar('(');
                puts("");
            }
        }
        else if(n % 2)
        {
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < m; j ++)
                    putchar('(' + j % 2);
                puts("");
            }
        }
        else if(m % 2)
        {
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < m; j ++)
                    putchar('(' + i % 2);
                puts("");
            }
        }
        else if(n > m)
        {
            for(int i = 0; i < n; i ++)
            {
                a[i][0] = '(';
                a[i][m-1] = ')';
            }
            for(int i = 0; i < m; i ++)
                a[0][i] = '(' + i % 2;
            for(int i = 1; i < n; i ++)
                for(int j = 1; j < m - 1; j ++)
                {
                    if(a[i - 1][j] == '(')    a[i][j] = ')';
                    else                     a[i][j] = '(';
                }
            for(int i = 0; i < n; i ++)
                puts(a[i]);
        }
        else
        {
            for(int i = 0; i < m; i ++)
            {
                a[0][i] = '(';
                a[n - 1][i] = ')';
            }
            for(int i = 0; i < n; i ++)
                a[i][0] = '(' + i % 2;
            for(int i = 1; i < n - 1; i ++)
                for(int j = 1; j < m; j ++)
                {
                    if(a[i][j - 1] == '(')    a[i][j] = ')';
                    else                     a[i][j] = '(';
                }
            for(int i = 0; i < n; i ++)
                puts(a[i]);
        }

    }
    return 0;
}
