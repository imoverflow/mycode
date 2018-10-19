#include <bits/stdc++.h>

using namespace std;
double eps=1e-8;
const int mod = 1e9 + 7;
long long quick(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
struct node
{
    double x, y;
} p[100], tp[100];
int s[100][100];
int ss[100][100];
int id[100];
int main()
{
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    int n, m, c;
    int t;

    scanf("%d", &t);
    while (t--)
    {
        memset(s,0,sizeof s);
        int cnt=1;
        scanf("%d%d%d", &n, &m, &c);
        double xx = 0, yy = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            xx += p[i].x, yy += p[i].y;
        }
        xx /= n, yy /= n;
        for (int i = 0; i < n; i++)
        {
            p[i].x -= xx;
            p[i].y -= yy;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            s[x][y] = s[y][x] = 1;
        }
        long long ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = ans * c % mod;
        }

        for (int k = 1; k < 4; k++)
        {
            int flag = 1;
            memset(id, 0, sizeof id);
            memset(ss, 0, sizeof ss);
            if (k == 1)
                for (int i = 0; i < n; i++)
                    tp[i].x = -p[i].y, tp[i].y = p[i].x;
            else if (k == 2)
                for (int i = 0; i < n; i++)
                    tp[i].x = -p[i].x, tp[i].y = -p[i].y;
            else if (k == 3)
                for (int i = 0; i < n; i++)
                    tp[i].x = p[i].y, tp[i].y = -p[i].x;

            for (int i = 0; i < n && flag; i++)
            {
                int temp = 0;

                for (int j = 0; j < n && !temp; j++)
                {
                    if (fabs(tp[j].x - p[i].x) < eps && fabs(tp[j].y - p[i].y) < eps)
                    {
                        temp = 1;
                        id[j] = i;
                    }
                }
                if (!temp)
                {
                    flag = 0;
                }
            }

            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    if (s[i][j])
                        ss[id[i]][id[j]] = 1;
                }
            }

            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    if (s[i][j] != ss[i][j])
                        flag = 0;
                }
            }
            if (flag)
            {
                int res=0;

                for(int i = 0; i < n; i++)
                {
                    if(id[i]==-1)
                        continue;
                    int j=i;
                    while(id[j]!=i&&j!=-1)
                    {
                        int t=j;
                        j=id[j];
                        id[t]=-1;
                    }
                    id[j]=-1;
                    res++;
                }
                ans+=quick(c,res);
                ans%=mod;
                cnt++;

            }
        }
        ans=ans*quick(cnt,mod-2)%mod;
        printf("%lld\n",ans);
    }

    return 0;
}




