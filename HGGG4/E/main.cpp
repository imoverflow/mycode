#include <bits/stdc++.h>
//#define x first
//#define y second
#define pb push_back
typedef long long ll;
const int N = 2e6+5;
const int inf = 0x3f3f3f3f;
const ll INF = 2e18+3;
const ll mod = 1e9+7;
const double PI = acos(-1.0);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
using namespace std;

long long powa(long long x,long long p)
{
    long long ans=1;
    for(long long i=0;i<p;i++)
    {
        ans*=x;
    }
    return ans;
}
//rotate/flip a quadrant appropriately
void rot(long long n, long long *x, long long *y, long long rx, long long ry) {
    if (ry == 0) {
        if (rx == 1) {
            *x = n-1 - *x;
            *y = n-1 - *y;
        }
        //Swap x and y
        int t  = *x;
        *x = *y;
        *y = t;
    }
}

void d2xy(long long n, long long d, long long *x, long long *y) {
    long long rx, ry, s, t=d;
    *x = *y = 0;
    for (s=1; s<n; s*=2) {
        rx = 1 & (t/2);
        ry = 1 & (t ^ rx);
        rot(s, x, y, rx, ry);
        *x += s * rx;
        *y += s * ry;
        t /= 4;
    }
}


int main()
{
    int t;  cin>>t;
//    ios::sync_with_stdio(false);
    while(t--)
    {
        ll a, b, n, x1= 0, y1 = 0, x2 = 0, y2 = 0;
        cin>>n>>a>>b;
//        cout<<powa(2,2*n)<<endl;
        d2xy(powa(2,2*n),a-1,&x1,&y1);
        d2xy(powa(2,2*n),b-1,&x2,&y2);
//        cout<<x1<<y1<<x2<<y2<<endl;
        long long ans=10*sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+0.5;
        printf("%lld\n",ans);
//        cout<<ans<<endl;
    }
    return 0;
}
