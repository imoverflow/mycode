#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct node{
    int val,index;
}s[100005];
bool cmp(const node &a,const node &b)
{
    return a.val>b.val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].val);
        s[i].index=i;
    }
    sort(s+1,s+n+1,cmp);
    if(n>=2&&s[1].val==s[2].val)
        printf("-1\n");
    else
        printf("%d\n",s[1].index);
    return 0;
}
