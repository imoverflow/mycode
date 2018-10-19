#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>V;
typedef pair<int , int > P;
const int inf = 0x3f3f3f3f;
const ll INF = 2e18;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 5+1e4;
const ll mod = 1e9+7;
ll dp[N], num[N], b[N], a[100];

int main()
{
//    freopen("C:\\Users\\zhangab\\Desktop\\exercise\\1.txt", "r", stdin);
    int t;  scanf("%d",&t);
    while(t--)
   {
        memset(dp, 0, sizeof dp);
        memset(num, 0, sizeof num);
        memset(b, 0, sizeof b);
        int n, m, cnt = 0, t0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= m; i ++)
            scanf("%lld", b+i);
        ll sum = 0;
        dp[0]=b[0];
        for(int i = 0; i <= m; i ++)
        {
            if(cnt>= n) break;
            if(b[sum+i]==0) continue;
            if(i==0)
            {
                t0 = b[0];
                while(b[0]>1)
                {
                    num[0]++;
                    b[0] >>= 1;
                }
                for(int j = cnt; j < cnt+num[i]; j ++)
                    a[j] = i;
                cnt += num[0];
            }
            else if(i==1)
            {
                num[1] = b[1]/t0;
                for(int j = cnt; j < cnt+num[i]; j ++)
                    a[j] = i;
                cnt += num[i];
                sum += num[i]*i;
            }
            else
            {
 //               memset(dp, 0, sizeof dp);
                //dp[0] = 1;
                for(int j = num[0]; j < cnt; j ++)
                {
//                    for(int k = i; k >= a[j]; k --)
//                    {
//                        dp[k] += dp[k-a[j]];
//                    }
                    dp[i]+=dp[i-a[j]];
                }
                num[i] = b[i]/t0 - dp[i];
                dp[i]=b[i];
                for(int j = cnt; j < cnt+num[i]; j ++)
                    a[j] = i;
                cnt += num[i];
                sum += num[i]*i;
            }
        }
        for(int i = 0; i < cnt; i ++)
            printf("%d ", a[i]);
        cout<<endl;
   }
    return 0;
}
