#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node1{
    long long x,m;
}s1[1003];
struct node2{
    long long x,m;
}s2[1003];
bool cmp1(const node1 &a,const node1 &b)
{
    if(a.x==b.x) return a.m>b.m;
    return a.x<b.x;
}
bool cmp2(const node2 &a,const node2 &b)
{
    if(a.x==b.x) return a.m>b.m;
    return a.x>b.x;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt1=0; //-
    int cnt2=0; //+
    for(int i=0;i<n;i++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a<0)
        {
            s1[cnt1].x=a;
            s1[cnt1++].m=b;
        }else{
            s2[cnt2].x=a;
            s2[cnt2++].m=b;
        }
    }
    sort(s1,s1+cnt1,cmp1);
    sort(s2,s2+cnt2,cmp2);
    long long ans=0;
    long long cap=0;
    for(int i=0;i<cnt1;i++)
    {
        cap=(k-s1[i].m%k)*(s1[i].m%k!=0);
        int z=i+1;
        while(cap>0&&z<cnt1)
        {
            if(s1[z].m<cap)
            {
                cap-=s1[z].m;
                s1[z++].m=0;
            }else{
                s1[z++].m-=cap;
                cap=0;
            }
        }
        ans+=2*abs(s1[i].x)*(s1[i].m/k+(s1[i].m%k!=0));
    }
    cap=0;
    for(int i=0;i<cnt2;i++)
    {
        cap=(k-s2[i].m%k)*(s2[i].m%k!=0);
        int z=i+1;
        while(cap>0&&z<cnt2)
        {
            if(s2[z].m<cap)
            {
                cap-=s2[z].m;
                s2[z++].m=0;
            }else{
                s2[z++].m-=cap;
                cap=0;
            }
        }
        ans+=2*abs(s2[i].x)*(s2[i].m/k+(s2[i].m%k!=0));
    }
    printf("%lld\n",ans);
    return 0;
}
