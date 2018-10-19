#include <iostream>
#include <stdio.h>
#define INF 1<<31
using namespace std;

//int btree[200005]={0};
//int stree[200005]={0};
int a[50005];
struct tr{
    int maxd;
    int mind;
}tree[200005];
void creatTree(int root,int istart,int iend)
{
    if(istart == iend)
    {
        tree[root].mind=a[istart];
        tree[root].maxd=a[istart];
    }
    else{
        int mid=(istart+iend)/2;
        creatTree(root*2+1,istart,mid);
        creatTree(root*2+2,mid+1,iend);
        tree[root].mind=min(tree[root*2+1].mind,tree[root*2+2].mind);
        tree[root].maxd=max(tree[root*2+1].maxd,tree[root*2+2].maxd);
    }
}

int query(int root,int nstart,int nend,int qstart,int qend)
{
    if(qstart>nend||qend<nstart)
        return 0;
    if(qstart <= nstart && qend >= nend)
        return tree[root].maxd-tree[root].mind;
    int mid=(nstart+nend)/2;
    return max(query(root*2+1,nstart,mid,qstart,qend),query(root*2+2,mid+1,nend,qstart,qend));
}

//int bquery(int root,int nstart,int nend,int qstart,int qend)
//{
//    if(qstart>nend||qend<nstart)
//        return 0;
//    if(qstart <= nstart && qend >= nend)
//        return btree[root];
//    int mid=(nstart+nend)/2;
//    return max(bquery(root*2+1,nstart,mid,qstart,qend),bquery(root*2+2,mid+1,nend,qstart,qend));
//}
int main()
{
    int n,q,l,r;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    creatTree(1,1,n);
    while(q--)
    {
        cin>>l>>r;
//        int ans1=bquery(1,1,n,l,r);
//        int ans2=squery(1,1,n,l,r);
        printf("%d\n",query(1,1,n,l,r));
    }
    return 0;
}
