#include <bits/stdc++.h>
using namespace std;

map<int,int>ma;                             /**��¼ÿ��Ԫ�ص�λ�ã���ȻҲ������������ٸ��Ӷȣ�**/
struct Link{
    int pre,next,num;
}s[500005];                                 /**������ȥģ������**/
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
            s[i].pre=i-1;                          /**ǰ��ָ��**/
            s[i].next=i+1;                         /**��n==i��ʱ��Ҫ��s[i].next��Ϊ0����Ȼ������ܻ���ָ���**/
            ma[s[i].num]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int l=ma[i],r=ma[i];
            int cnt1=0,cnt2=0;
            int x[100]={0};                       /**��¼�ж��ٸ���xС������**/
            for(int j=0;j<k;j++)                  /**������k����x���**/
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
            s[s[ma[i]].pre].next=s[ma[i]].next;          /**����ط�����3��Сʱ��bug**/
            s[s[ma[i]].next].pre=s[ma[i]].pre;           /**���Լ��Ĵ���̫��**/
        }
        printf("%lld\n",ans);
    }
    return 0;
}
