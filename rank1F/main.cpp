#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct time{
    int index;
    int val;
}s[1005];
bool cmp(const struct time &a,const struct time &b)
{
    return a.val<b.val;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        s[i].index=i+1;
        scanf("%d",&s[i].val);
    }
    sort(s,s+n,cmp);
    int cou=0,ans=0;
    while(k>=s[cou].val&&cou<n)
    {
        ans++;
        k-=s[cou].val;
        cou++;
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
    {
        printf("%d",s[i].index);
        if(i!=ans-1)
            printf(" ");
    }
    return 0;
}
