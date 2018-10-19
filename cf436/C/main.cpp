#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long ss[10004*2];
int main()
{
    long long a,b,f,k;
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&f,&k);
    for(int i=0;i<k;i++)
    {
        if(i%2==0)
            ss[i]=f+a*i;
        else
            ss[i]=a*i+(a-f);
    }
    ss[k]=k*a;
//    for(int i=0;i<=2*k;i++)
//    {
//        printf("%d ",ss[i]);
//    }
//    priority_queue<long long>que;
    long long ans=0,pos=0,tank=b;
    for(int i=0;i<k+1;i++)
    {
        long long d=ss[i]-pos;
        if(b<d)
        {
            puts("-1");
            return 0;
        }
        if(tank-d<0)
        {
            tank=b;
            ans++;
        }
        tank-=d;
        pos=ss[i];
    }
    printf("%I64d\n",ans);
    return 0;
}
