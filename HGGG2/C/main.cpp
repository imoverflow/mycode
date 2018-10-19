#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k,r;
int a[100005];
struct tr{
    int sum;
//    int mind;
}tree[100005*4];
void creatTree(int root,int istart,int iend)
{
    if(istart == iend)
    {
//        tree[root].mind=a[istart];
//        tree[root].maxd=a[istart];
        tree[root].sum=a[istart];
    }
    else{
        int mid=(istart+iend)/2;
        creatTree(root*2+1,istart,mid);
        creatTree(root*2+2,mid+1,iend);
//        tree[root].mind=min(tree[root*2+1].mind,tree[root*2+2].mind);
//        tree[root].maxd=max(tree[root*2+1].maxd,tree[root*2+2].maxd);
        tree[root].sum=tree[root*2+1].sum+tree[root*2+2].sum;
    }
}

int query(int root,int nstart,int nend,int qstart,int qend)
{
    if(qstart>nend||qend<nstart)
        return 0;
    if(qstart <= nstart && qend >= nend)
//        return tree[root].maxd-tree[root].mind;
        return tree[root].sum;
    int mid=(nstart+nend)/2;
//    return max(query(root*2+1,nstart,mid,qstart,qend),query(root*2+2,mid+1,nend,qstart,qend));
    return query(root*2+1,nstart,mid,qstart,qend)+query(root*2+2,mid+1,nend,qstart,qend);
}
void update(int root,int l,int r,int pos,int val)
{
    if(l==r&&l==pos)
    {
        tree[root].sum=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(root*2+1,l,mid,pos,val);
    else
        update(root*2+2,mid+1,r,pos,val);
    tree[root].sum=tree[root*2+1].sum+tree[root*2+2].sum;
}
int main()
{
    scanf("%d%d%d",&n,&k,&r);
    for(int i=0;i<k;i++)
    {
        int b;
        scanf("%d",&b);
        a[b]=1;
    }
    creatTree(1,1,n);
    int res=0;
    for(int i=1;i<=n-r+1;i++)
    {
        int p=query(1,1,n,i,i+r-1);
        if(p<2)
        {
            res+=2-p;
            for(int j=0,k=i+r-1;j<2-p;k--)
            {
                if(a[k]==0)
                {
                    j++;
                    update(1,1,n,k,1);
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
