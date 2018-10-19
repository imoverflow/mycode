#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    long long x,k,c,cou=0,v[100000]={-1};
    int t;
    long long m;
    scanf("%d",&t);
    for(int l=1;l<=t;l++)
    {
        cou=0;
        memset(v,-1,sizeof(v));
        scanf("%lld%lld%lld%lld",&x,&m,&k,&c);
        int res=x%k;
        v[cou++]=res;
        for(long long i=0;i<m-1;i++)
        {
            res=(10*res+x)%k;
            v[cou++]=res;
            if(res==v[0])
                break;
        }
        printf("Case #%d:\n",l);
        if(m%cou!=0&&v[m%cou-1]==c||res==c||m%cou==0&&v[cou-1]==c)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
