#include <iostream>
#include <stdio.h>

using namespace std;

long long prime[1000000];
long long fact(long long n)
{
    int num=0;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime[num++]=i;
            while(n>0&&n%i==0)
                n/=i;
        }
    }
    if(n>1)
        prime[num++]=n;
    return num;
}
long long pric(long long lim,long long num)
{
    long long ans=0;
    for(long long i=1;i<(long long)(1<<num);i++)
    {
        int flag=0,temp=1;
        for(long long j=0;j<num;j++)
        {
            if(i&(long long)(1<<j))
            {
                flag++;
                temp*=prime[j];
            }
        }
        if(flag&1)
            ans+=lim/temp;
        else
            ans-=lim/temp;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long a,b,n;
        scanf("%lld%lld%lld",&a,&b,&n);
        long long p=fact(n);
        long long ans=(b-pric(b,p))-(a-1-pric(a-1,p));
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
