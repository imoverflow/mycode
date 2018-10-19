#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m,cl,ce,v;
int stair[100005];
int ele[100005];

void solve(int x1,int y1,int x2,int y2)
{
    int ans=INF;
    if(x1==x2)
    {
        cout<<abs(y1-y2)<<endl;
        return;
    }
    int p=lower_bound(stair,stair+cl,y1)-stair;
    if(p!=cl)
        ans=min(ans,abs(stair[p]-y1)+abs(x2-x1)+abs(y2-stair[p]));
    if(--p>=0)
        ans=min(ans,abs(stair[p]-y1)+abs(x2-x1)+abs(y2-stair[p]));
    p=lower_bound(ele,ele+ce,y1)-ele;
    if(p!=ce)
        ans=min(ans,abs(ele[p]-y1)+abs(x2-x1)/v+(abs(x2-x1)%v!=0)+abs(ele[p]-y2));
    if(--p>=0)
        ans=min(ans,abs(ele[p]-y1)+abs(x2-x1)/v+(abs(x2-x1)%v!=0)+abs(ele[p]-y2));
    cout<<ans<<endl;
}
int main()
{
    cin>>n>>m>>cl>>ce>>v;
    for(int i=0;i<cl;i++)
    {
        scanf("%d",&stair[i]);
    }
    for(int i=0;i<ce;i++)
    {
        scanf("%d",&ele[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        solve(x1,y1,x2,y2);
    }
    return 0;
}
