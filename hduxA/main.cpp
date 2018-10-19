#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 1<<10
using namespace std;

int s[2000];
int calh(int x)
{
    return x/60;
}

int calm(int x)
{
    return x%60;
}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));
        int t,ans,cnt=0;
        scanf("%d",&t);
        for(int i=0;i<n;i++){
            scanf("%d:%d",&a,&b);
            s[a*60+b]++;
        }
        for(int i=0;i<=1440;i++)
        {
            if(i>=t&&s[i-t]) s[i]+=s[i-t];
            if(s[i]) cnt+=s[i];
            if(cnt>=m){
                ans=i;
                break;
            }
        }
        int hh=calh(ans);
        int mm=calm(ans);
        if(hh<10)
            printf("0%d:",hh);
        else
            printf("%d:",hh);
        if(mm<10)
            printf("0%d\n",mm);
        else
            printf("%d\n",mm);
    }
    return 0;
}
