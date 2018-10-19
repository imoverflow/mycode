#include<bits/stdc++.h>
#define x first
#define y second
#define ok cout << "ok" << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=5e6+9;
const double Eps=1e-7;

const int _2_30 = 1 << 30;
unsigned x, y, z, w, f[9];
int n, m, T;
int l, r, v;
long long ans[N<<2];
inline unsigned func()
{
    x = x ^ (x << 11);
    x = x ^ (x >> 4);
    x = x ^ (x << 5);
    x = x ^ (x >> 14);
    w = x ^ y ^ z;
    x = y;
    y = z;
    z = w;
    return z;
}
void pushup(int root)
{
    ans[root]=min(ans[root<<1],ans[root<<1|1]);
}
void update(int root,int l,int r,int L,int R,unsigned c)
{
    if(ans[root]>=c)
        return;
    if(L==R)
    {
        ans[root]=c;
        return;
    }
    int mid=(L+R)>>1;
    if(l<=mid)
        update(root<<1,l,r,L,mid,c);
    if(r>mid)
        update(root<<1|1,l,r,mid+1,R,c);
    pushup(root);
}
int query(int root,int x,int L,int R)
{
    if(L==R)
        return ans[root];
    int mid=(L+R)>>1;
    if(x<=mid)
        query(root<<1,x,L,mid);
    else
        query(root<<1|1,x,mid+1,R);
}
int main(void)
{
    //clock_t ti = clock();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%u%u%u", &n, &m, &x, &y, &z);
        memset(ans,0,sizeof(long long)*(n<<2));
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j <= 3; j++)
                f[j] = func();
            l = min((f[1] % n) + 1, f[2] % n + 1);
            r = max((f[1] % n) + 1, f[2] % n + 1);
            v = f[3] % _2_30;
            update(1,l,r,1,n,v);
        }
        long long res=0;
        for(int i=1;i<=n;i++)
        {
            res^=1LL*i*query(1,i,1,n);
        }
        printf("%lld\n",res);
    }
    return 0;
}
