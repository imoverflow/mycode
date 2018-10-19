#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int index,score,cost;
}s[1005];
bool cmp(node &a,node &b)
{
    if(a.cost==b.cost) return a.index<b.index;
    return a.cost<b.cost;
}
int main()
{
    int b,n,cases=1;
    while(~scanf("%d%d",&b,&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i].score,&s[i].cost);
            s[i].index=i;
        }
        sort(s+1,s+n+1,cmp);
        int l=1,r=1;
        int mal=0,mar=0;
        int ans=0;
        while(r<=n&&l<=r)
        {
            int sum=0;
            int cos=0;
            for(int i=l;i<=r;i++)
            {
                cos+=s[i].cost;
                sum+=s[i].score;
            }
            if(ans<sum&&cos<=b)
            {
                ans=sum;
                mal=l;
                mar=r;
                r++;
            }else{
                l++;
            }
        }
        printf("Case #%d:\n%d\n",cases++,ans);
        for(int i=mal;i<=mar;i++)
        {
            if(i==mal)
                printf("%d",s[i].index);
            else
                printf(" %d",s[i].index);
        }
        printf("\n");
    }

    return 0;
}
