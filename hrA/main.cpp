#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1<<30
using namespace std;
int s[100050];
int tree[500500];
void creatTree(int root,int istart,int iend)
{
    if(istart == iend)
    {
        tree[root]=s[istart];
    }
    else{
        int mid=(istart+iend)/2;
        creatTree(root*2+1,istart,mid);
        creatTree(root*2+2,mid+1,iend);
        tree[root]=min(tree[root*2+1],tree[root*2+2]);
    }
}
long long query(int root,int nstart,int nend,int qstart,int qend)
{
    if(qstart>nend||qend<nstart)
        return INF;
    if(qstart <= nstart && qend >= nend)
        return tree[root];
    int mid=(nstart+nend)/2;
    return min(query(root*2+1,nstart,mid,qstart,qend),query(root*2+2,mid+1,nend,qstart,qend));
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof s);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
        memset(tree,0,sizeof(tree));
        creatTree(1,1,n);
        int l=1,r=n;
        long long ans=0,sq;
        while(l<=r)
        {
            long long h=query(1,1,n,l,r);
            sq=h*(r-l+1);
            if(sq>=ans)
            {
                ans=sq;
            }
            if(l<r)
            {
                for(int i=l,j=r;i<j;i++,j--)
                {
                    int p=s[i]-s[i+1];
                    int m=s[j]-s[j-1];
                    if(p>=0&&m>=0&&p>m){
                        l++;
                        break;
                    }else if(p>=0&&m>=0&&p<m){
                        r--;
                        break;
                    }else if(p<=0&&m<=0&&p<m){
                        r--;
                        break;
                    }else if(p<=0&&m>=0&&p<m){
                        l++;
                        break;
                    }
                    if(i==j-1)
                    {
                        if(s[i]>s[j-1])
                        {
                            r--;
                            break;
                        }else{
                            l++;
                            break;
                        }
                    }else if(i==j-2)
                    {
                        if(s[i]>s[j-2])
                        {
                            r--;
                            break;
                        }else{
                            l++;
                            break;
                        }
                    }
                }
            }else{
                r--;
            }
//            if(s[l]>s[r])
//                r--;
//            else if(s[l]<s[r])
//                l++;
//            else if(s[l]==s[r])
//            {
//                for(int i=l,j=r;i<=j;i++,j--){
//                    if(s[i]>s[j])
//                    {
//                        r--;
//                        break;
//                    }else if(s[i]<s[j])
//                    {
//                        l++;
//                        break;
//                    }
//                    if(i==j-1||i==j)
//                    {
//                        l++;
//                        break;
//                    }
//                }
//            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
