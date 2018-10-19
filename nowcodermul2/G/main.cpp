#include <bits/stdc++.h>

using namespace std;

long long presum[500005];
long long precost[500005];
long long sufsum[500005];
long long sufcost[500005];
long long n,t;

struct node{
    long long x,a;
}s[500006];

long long calpre(int l,int r)
{
    return precost[r]-precost[l-1]-presum[l-1]*(s[r].x-s[l-1].x);
}
long long calsuf(int l,int r)
{
    return sufcost[l]-sufcost[r+1]-sufsum[r+1]*(s[r+1].x-s[l].x);
}
bool check(long long x)
{
    int l=1,r=1,i=1;
    long long mid=x/2+1;
    while(1)
    {
        while(r<=n&&presum[r]-presum[l-1]<x) r++;
        while(i<=n&&presum[i]-presum[l-1]<mid) i++;
        if(r>n||i>r) break;
        long long rest=presum[r]-presum[l-1]-x;
//        cout<<"cost="<<calpre(i,r)+calsuf(l,i)-(s[r].x-s[i].x)*rest<<endl;
//        cout<<"N1"<<endl;
        if(calpre(l,i)+calsuf(i,r)-(s[r].x-s[i].x)*rest<=t){
            return true;
        }
        l++;
    }
    l=r=i=n;
    while(1)
    {
        while(l>=1&&presum[r]-presum[l-1]<x) l--;
        while(i>=2&&presum[r]-presum[i-1]<mid) i--;
        if(l<1||i<l) break;
        long long rest=presum[r]-presum[l-1]-x;
//        cout<<"cost="<<calpre(i,r)+calsuf(l,i)-(s[i].x-s[l].x)*rest<<endl;
//        cout<<"N2"<<endl;
        if(calpre(l,i)+calsuf(i,r)-(s[i].x-s[l].x)*rest<=t){
            return true;
        }
        r--;
    }
    return false;
}


void init()
{
    for(int i=1;i<=n;i++) presum[i]=presum[i-1]+s[i].a;
    for(int i=n;i>=1;i--) sufsum[i]=sufsum[i+1]+s[i].a;
    for(int i=1;i<=n;i++) precost[i]=precost[i-1]+(s[i].x-s[i-1].x)*presum[i-1];
    for(int i=n;i>=1;i--) sufcost[i]=sufcost[i+1]+(s[i+1].x-s[i].x)*sufsum[i+1];
}
int main()
{
//    long long sum=0;
    scanf("%lld%lld",&n,&t);
    t/=2;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i].x);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i].a);
    }
    init();
//    cout<<calpre(1,2)<<endl;
    long long l=0,r=presum[n];
    long long ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid)) l=mid+1,ans=mid;
//        printf("%lld\n",mid);
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
