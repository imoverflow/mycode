#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans[100005][32];
int ans1[100005];
int s[100];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    if(n==1)
    {
        printf("YES\n");
        printf("%d\n",x);
        return 0;
    }
    if(n==2&&x==0)
    {
        printf("NO\n");
        return 0;
    }
    if(n==2)
    {
        printf("YES\n");
        printf("%d %d\n",0,x);
        return 0;
    }
    printf("YES\n");
    int t=0;
    for(int i=1;i<=n-3;i++)
    {
        printf("%d ",i);
        t^=i;
    }
    printf("%d %d %d\n",1<<17,1<<18,t^(1<<17)^(1<<18)^x);
    return 0;
}
