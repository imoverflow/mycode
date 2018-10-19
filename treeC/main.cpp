#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 1<<31
using namespace std;

int tree[200005]={0};
int a[50005];
void creatTree(int root,int istart,int iend)
{
    if(istart == iend)
    {
        tree[root]=a[istart];
    }
    else{
        int mid=(istart+iend)/2;
        creatTree(root*2+1,istart,mid);
        creatTree(root*2+2,mid+1,iend);
        tree[root]=tree[root*2+1]+tree[root*2+2];
    }
}

int query(int root,int nstart,int nend,int qstart,int qend)
{
    if(qstart>nend||qend<nstart)
        return 0;
    if(qstart <= nstart && qend >= nend)
        return tree[root];
    int mid=(nstart+nend)/2;
    int res=0;
    if(qstart<=mid) res+=query(root*2+1,nstart,mid,qstart,qend);
    if(qend>mid) res+=query(root*2+2,mid+1,nend,qstart,qend);
    return res;
}

void add(int root,int ll,int rr,int x,int y)
{
    if(x>=ll&&x<=rr)
        tree[root]+=y;
    if(ll==rr)
        return;
    int mid=(ll+rr)/2;
    if(x<=mid) add(root*2+1,ll,mid,x,y);
    if(x>mid) add(root*2+2,mid+1,rr,x,y);
}

void sub(int root,int ll,int rr,int x,int y)
{
    if(x>=ll&&x<=rr)
        tree[root]-=y;
    if(ll==rr)
        return;
    int mid=(ll+rr)/2;
    if(x<=mid) sub(root*2+1,ll,mid,x,y);
    if(x>mid) sub(root*2+2,mid+1,rr,x,y);
}
int main()
{
    int n,q,l,t,r,x,y;
    char s[100];
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        creatTree(1,1,n);
        printf("Case %d:\n",z);
        while(scanf("%s",s))
        {
            if(s[0]!='E')
            {
                scanf("%d%d",&x,&y);
                if(s[0]=='Q')
                    printf("%d\n",query(1,1,n,x,y));
                if(s[0]=='A')
                    add(1,1,n,x,y);
                if(s[0]=='S')
                    sub(1,1,n,x,y);
            }else{
                break;
            }
        }
    }
    return 0;
}
