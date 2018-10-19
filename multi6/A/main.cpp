#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>V;
typedef pair<int , int > P;
const int inf = 0x3f3f3f3f;
const ll INF = 2e18;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 5+1e5;
const ll mod = 1e9+7;
bool used[N];
int b[N];

struct node
{
    int num, val;
}a[N];

 bool cmp(const node&a, const node& b)
 {
     return a.val>b.val;
 }

int main()
{
//    freopen("C:\\Users\\zhangab\\Desktop\\exercise\\1.txt", "r", stdin);
    int  t; cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i].val);
            a[i].num = i;
        }
        sort(a+1, a+n+1, cmp);
        memset(used, 0,sizeof used);
        for(int j = 1; j <= n; j ++)
        {
//            if(used[i]==1) continue;
//            used[i] = 1;
            for(int i = 1; j <= n; j ++)
             {
                 if(a[j].num%i!=0)
                 {
                     b[i] = a[j].val;
                     for(int k = a[j].num+i ; k <= n; k += a[j].num)
                     {
                         used[k] = 1;
                         b[k] = a[j].val;
                     }
                     break;
                 }
             }
        }
        for(int i = 2; i < n; i ++)
        {
            printf("%d ", b[i]);
        }
        printf("%d\n", b[n]);
    }
    return 0;
}
