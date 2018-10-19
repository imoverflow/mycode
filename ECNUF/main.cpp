#include <iostream>
#include <stdio.h>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int tre[5000];
int laz[5000];
void pushdown(int num)
{
    if(laz[num]!=0)
    {
        tre[num*2]+=laz[num];
        tre[num*2+1]+=laz[num];
        laz[num*2]+=laz[num];
        laz[num*2+1]+=laz[num];
        laz[num]=0;
    }
}
void update(int num,int le,int ri,int x,int y)
{
    if(x<=le&&y>=ri)
    {
        tre[num]++;
        laz[num]++;
        return ;
    }
    pushdown(num);
    int mid=(le+ri)/2;
    if(x<=mid)
        update(num*2,le,mid,x,y);
    if(y>mid)
        update(num*2+1,mid+1,ri,x,y);
}

int query(int num,int le,int ri,int x)
{
    if(le==ri)
    {
        return tre[num];
    }
    pushdown(num);
    int mid=(le+ri)/2;
    if(x<=mid)
        return query(num*2,le,mid,x);
    else
        return query(num*2+1,mid+1,ri,x);
}
int main()
{
    int t;
    cin>>t;
    int n,m,k;
    for(int cas=1;cas<=t;cas++)
    {
        memset(tre,0,sizeof(tre));
        memset(laz,0,sizeof(laz));
        scanf("%d%d%d",&n,&m,&k);

    }
    return 0;
}
