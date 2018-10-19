#include <iostream>
#include <bits/stdc++.h>
#define INF 1<<30
using namespace std;

char s[200005];
int n,c1,c2;
int pup=0,par=0;
long long check(int x)
{
    if(x>par) return 100000000000000000;
    if(n%x==0)
        return x*(c1+c2*(n/x-1)*(n/x-1));
    else
        return (x-1)*(c1+c2*(n/x-1)*(n/x-1))+c1+c2*(n/x+n%x-1)*(n/x+n%x-1);
}
int main()
{
    cin>>n>>c1>>c2;
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
            pup++;
        else
            par++;
    }
    long long ans=min(check(1),check(n));
    int l=1,r=n,cnt=0;
    while(l<r)
    {
        int lmid=(r-l)/3+l,rmid=r-(r-l)/3;
        long long x1=check(lmid),x2=check(rmid);
        if(x1<x2)
        {
            ans=min(ans,x1);
            l=lmid+1;
        }else
        {
            ans=min(ans,x2);
            r=rmid-1;
        }
//        if(x1<x2)
//        {
//            r=rmid;
//            ans=min(ans,x1);
//        }else
//        {
//            l=lmid;
//            ans=min(ans,x2);
//        }
//        cnt++;
//        if(cnt>1e5)
//            break;
    }
    ans=min(ans,check(l+1));
    ans=min(ans,check(l+2));
    ans=min(ans,check(l+3));
    ans=min(ans,check(l+4));
    printf("%I64d",ans);
    return 0;
}
