#include <bits/stdc++.h>

using namespace std;
const int INF=0x3f3f3f3f;
const int N1=(int)(1e5+7)<<3;
const int N2=1e5+7;
long long tree[N1],p[N1];
long long s[N2],ans[N1],rest[N1];//ans rest换成N2会段错误
void pushup(int rt,int l,int r){
    tree[rt]=min(tree[l],tree[r]);
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=s[l];
        p[rt]=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt,rt<<1,rt<<1|1);
}
void update(int l,int r,int rt,int pos){
    if(l==r){
        tree[rt]=INF;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos);
    else update(mid+1,r,rt<<1|1,pos);
    pushup(rt,rt<<1,rt<<1|1);
}
int query(int l,int r,int rt,long long k){
    if(l==r){
        return rt;
    }
    int mid=(l+r)>>1;
    if(tree[rt<<1]<=k) return query(l,mid,rt<<1,k);      //先查左子树再查右子树
    else return query(mid+1,r,rt<<1|1,k);
}
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
    }
    build(1,n,1);
    long long res=0,tot=0,id=INF,pos;
    for(int i=1;i<N1;i++)
    {
         res+=m;
         if(res<tree[1]){
            ans[i]=ans[i-1];
            rest[i]=res;
         }else{
            int t=0;
            while(res>=tree[1])
            {
                int q=query(1,n,1,res);
                res-=tree[q];
                pos=p[q];
                update(1,n,1,pos);
                t++,tot++;
                if(tot==n)
                {
                    id=i;
                    break;
                }
            }
            ans[i]=ans[i-1]+t;
            rest[i]=res;
         }
         if(id!=INF)
            break;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a;
        scanf("%d",&a);
        printf("%lld %lld\n",a>=id?ans[id]:ans[a],a>=id?rest[id]:rest[a]);
    }
    return 0;
}
