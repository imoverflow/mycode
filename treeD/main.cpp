#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 1<<31
using namespace std;

int n,sum;

struct node
{
    int l,r,n;
} a[50005<<2];

void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].n = 1;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(l,mid,2*i);
        init(mid+1,r,2*i+1);
    }
}
void insert(int i,int x,int y,int m)
{
    if(a[i].n == m)
        return ;
    if(a[i].l == x && a[i].r == y)
    {
        a[i].n = m;
        return ;
    }
    if(a[i].n != -1)
    {
        a[2*i].n = a[2*i+1].n = a[i].n;
        a[i].n = -1;
    }
    int mid = (a[i].l+a[i].r)>>1;
    if(x>mid)
    insert(2*i+1,x,y,m);
    else if(y<=mid)
    insert(2*i,x,y,m);
    else
    {
        insert(2*i,x,mid,m);
        insert(2*i+1,mid+1,y,m);
    }
}
int find(int i)//区间求和
{
    if(a[i].n != -1)//纯色直接算这个区间
    return (a[i].r - a[i].l+1)*a[i].n;
    else//不存则左右子树去找
    return find(i*2)+find(i*2+1);
}

int main()
{
    int q,l,t,r,x,y,c,d,e;
    char s[100];
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n;
        init(1,n,1);
        cin>>q;
        while(q--)
        {
            scanf("%d%d%d",&c,&d,&e);
            insert(1,c,d,e);
        }
        printf("Case %d: The total value of the hook is %d.\n",z,find(1));
    }
    return 0;
}
