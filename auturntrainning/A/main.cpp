#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int N = 1e6+5;
const int inf = 0x3f3f3f3f;
const ll INF = 2e18+3;
using namespace std;
typedef vector<int> V;
typedef pair<int, int> P;

struct matrix
{
    int m[2][2];
    void init0()
    {
        memset(m, 0, sizeof m);
    }
    void init()
    {
        init0();
        m[0][0] = m[1][1] = 1;
    }
}ans[6];

void init1(int x, int y, matrix &b)
{
    b.m[0][0] = x;
    b.m[1][1] = y;
}

void init2(int x, int y, matrix &b)
{
    b.m[0][1] = x;
    b.m[1][0] = y;
}

matrix operator *(const matrix &a, const matrix &b)
{
    matrix c;   c.init0();
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
    return c;
}

int main()
{
    init1(1, -1, ans[0]);     init1(-1, 1, ans[1]);     init2(-1, -1, ans[5]);
    init2(-1, 1, ans[2]);     init2(1, -1, ans[3]);     init2(1, 1, ans[4]);
    int n;
    while(~scanf("%d", &n))
    {
        matrix f ;  f.init();
        char s[105][105];
        for(int i = 0; i < n; i ++)
            scanf("%s", s[i]);
        map<char, int> m;
        char a[15] = "v>^<\\/-|xo";
        for(int i = 0; i < 10; i ++)
            m[a[i]] = i;
        char x, y;
        getchar();
        string aaa;
        getline(cin, aaa);
        for(int k = 0, len = aaa.length(); k < len; k ++)
        {
            x = aaa[k];
            if(x==' ') continue;
            if(x=='-')
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='v')   a[i] = '^';
                    else if(a[i]=='^')   a[i] = 'v';
                    else if(a[i]==47)    a[i] = 92;
                    else if(a[i]==92)    a[i] = 47;
                }
            }
            else if(x=='|')
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='>')   a[i] = '<';
                    else if(a[i]=='<')   a[i] = '>';
                    else if(a[i]==47)    a[i] = 92;
                    else if(a[i]==92)    a[i] = 47;
                }
            }
            else if(x=='<')
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='>')   a[i] = '^';
                    else if(a[i]=='<')   a[i] = 'v';
                    else if(a[i]=='v')   a[i] = '>';
                    else if(a[i]=='^')   a[i] = '<';
                    else if(a[i]==47)    a[i] = 92;
                    else if(a[i]==92)    a[i] = 47;
                    else if(a[i]=='|')   a[i] = '-';
                    else if(a[i]=='-')   a[i] = '|';
                }
            }
            else if(x=='>')
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='>')   a[i] = 'v';
                    else if(a[i]=='<')   a[i] = '^';
                    else if(a[i]=='v')   a[i] = '<';
                    else if(a[i]=='^')   a[i] = '>';
                    else if(a[i]==47)    a[i] = 92;
                    else if(a[i]==92)    a[i] = 47;
                    else if(a[i]=='|')   a[i] = '-';
                    else if(a[i]=='-')   a[i] = '|';
                }
            }
            else if(x=='/')
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='v')   a[i] = '<';
                    else if(a[i]=='^')   a[i] = '>';
                    else if(a[i]=='>')   a[i] = '^';
                    else if(a[i]=='<')   a[i] = 'v';
                    else if(a[i]=='-')  a[i] = '|';
                    else if(a[i]=='|')  a[i] = '-';
                }
            }
            else
            {
                for(int i = 0; i < 8; i ++)
                {
                    if(a[i]=='v')   a[i] = '>';
                    else if(a[i]=='^')   a[i] = '<';
                    else if(a[i]=='>')   a[i] = 'v';
                    else if(a[i]=='<')   a[i] = '^';
                    else if(a[i]=='-')  a[i] = '|';
                    else if(a[i]=='|')  a[i] = '-';
                }
            }
        }
        for(int k = aaa.length(); k ; k --)
        {
            x = aaa[k-1];
            if(x==' ') continue;
            if(x=='-')
            {
                f = f * ans[0];
            }
            else if(x=='|')
            {
                f = f * ans[1];
            }
            else if(x=='<')
            {
                f = f * ans[2];
            }
            else if(x=='>')
            {
                f = f * ans[3];
            }
            else if(x=='/')
            {
                f = f * ans[4];
            }
            else
            {
                f = f * ans[5];
            }
        }
        char out[105][105];
        memset(out, 0, sizeof out);
        for(int i = 0, y1 = n/2; i < n; i ++, y1 --)
        {
            if(n%2==0 && y1 == 0)    y1--;
            for(int j = 0, x1 = -n/2; j < n; j ++, x1 ++)
            {
                if(n%2==0 && x1==0) x1 ++;
                int xx = f.m[0][0]*x1 + f.m[0][1]*y1 ;
                int yy = f.m[1][0]*x1 + f.m[1][1]*y1 ;
                int fx = i+(xx-x1), fy = j - (yy-y1);
                out[fx][fy] = a[m[s[i][j]]];
            }
        }
        for(int i = 0; i < n; i ++)
            puts(out[i]);
    }
    return 0;
}
