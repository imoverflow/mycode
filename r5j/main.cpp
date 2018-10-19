#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int ans;
int pre[1005];
int fin(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        r=pre[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=fin(x),fy=fin(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
        ans--;
    }
}
int main()
{
    //freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<1000;i++)
        {
            pre[i]=i;
        }
        int N,M,a,b;
        cin>>N>>M;
        ans=N;
        for(int i =0;i<M;i++)
        {
            cin>>a>>b;
            join(a,b);
        }
        printf("%d\n",ans);
    }
    return 0;
}
