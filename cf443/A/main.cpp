#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b;
}s[1000006];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
    }
    int ans=s[0].a;
    int preday=s[0].a;
    for(int i=1;i<n;i++)
    {
        int t=ceil(1.0*(preday-s[i].a)/s[i].b)+((preday-s[i].a)%s[i].b==0);
        preday=s[i].a+s[i].b*t;
        ans=preday;
    }
    printf("%d\n",ans);
    return 0;
}
