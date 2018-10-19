#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

char s[50];
long long f(int l,int r)
{
    long long ans=0;
    for(long long i=r-1,j=1;i>=l;i--,j*=10)
    {
        ans+=(s[i]-'0')*j;
    }
    return ans;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
//        printf("%lld\n",f(0,1));
//        printf("%lld\n",f(1,2));
//        printf("%lld\n",f(2,3));
//        printf("%lld\n",f(3,4));
        int len=strlen(s);
        long long ans=-INF;
        long long fir,sec,thi,fou;
        for(int i=1;i<len-3;i++)
        {
            fir=f(0,i);
            for(int j=i+1;j<len-2;j++)
            {
                sec=f(i,j);
                thi=f(j,j+1);
                fou=f(j+1,j+2);
//                    cout<<thi<<fou<<endl;
                ans=max(ans,fir+sec-thi*fou/f(j+2,len));
//                printf("%d %d %lld %lld %lld %lld %lld\n",i,j,fir,sec,thi,fou,f(j+2,len));
            }
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
