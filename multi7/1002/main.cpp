#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long num[105];
long long mod_pow(long long x,long long n)
{
    long long res=1;
    while(n>0)
    {
        if(n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}
void init(long long n,long long depth)
{
    for(int i=1;i<=depth;i++)
    {
        num[i]=(mod_pow(n,i)-1)/(n-1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if(k==1)
        {
            if(n%4==0)
                printf("%lld\n",n);
            else if(n%4==1)
                printf("%lld\n",1);
            else if(n%4==2)
                printf("%lld\n",n+1);
            else
                printf("%lld\n",0);
            continue;
        }
        long long ans=n;
        int depth=1;
        long long res=n-1;
        while(res>0)
        {
            res=(res-1)/k;
            depth++;
        }
        init(k,depth);
        ans^=(n-num[depth-1])&1;
        //处理最后一层
        depth--;
        int now=2;
        long long pos=(n-2)/k;
        while(depth>1)
        {
            long long l=num[depth-1];
            long long r=num[depth]-1;
            long long ltree=num[now];
            long long rtree=num[now-1];
            if((pos-l)%2)
            {
                ans^=ltree;
            }
            if((r-pos)%2)
            {
                ans^=rtree;
            }
            long long cnt=pos;
            while(cnt<=(n-2)/k)
            {
                cnt=cnt*k+1;
            }
            ans^=num[now-1]+n-cnt;
            now++;
            depth--;
            pos=(pos-1)/k;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
