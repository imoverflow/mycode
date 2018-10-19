#include <bits/stdc++.h>
using namespace std;

map<int,int>ma;                             /**记录每个元素的位置（当然也可以用数组减少复杂度）**/
struct Link{
    int pre,next,num;
}s[500005];                                 /**用数组去模拟链表**/
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        memset(s,0,sizeof s);
        ma.clear();
        long long sum=0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i].num);
            s[i].pre=i-1;                          /**前后指针**/
            s[i].next=i+1;                         /**当n==i的时候不要把s[i].next设为0，不然结果可能会出现负数**/
            ma[s[i].num]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int l=ma[i],r=ma[i];
            int cnt1=0,cnt2=0;
            int x[100]={0};                       /**记录有多少个比x小的数字**/
            for(int j=0;j<k;j++)                  /**往右找k个比x大的**/
            {
                if(s[r].next!=0)
                {
                    x[++cnt2]=s[r].next-r;
                    r=s[r].next;
                }else break;
            }
            long long res=0;
            for(int j=l;j>0&&cnt1<k;j=s[j].pre)
            {
                cnt1++;
                if(k-cnt1-cnt2+1>0) continue;
                else res+=(j-s[j].pre)*x[k-cnt1+1];
            }
            ans+=res*i;
            s[s[ma[i]].pre].next=s[ma[i]].next;          /**这个地方调了3个小时的bug**/
            s[s[ma[i]].next].pre=s[ma[i]].pre;           /**怪自己的代码太丑**/
        }
        printf("%lld\n",ans);
    }
    return 0;
}
