#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <math.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int s[1000];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+m);
        long long ans=0;
        for(int i=0;i<min(n,m);i++)
        {
            ans+=s[m-i-1];
        }
//        if(n>=m)
//        {
//            ans+=(n-m)*s[m-1];
//        }
        printf("%lld\n",ans);
    }
    return 0;
}
