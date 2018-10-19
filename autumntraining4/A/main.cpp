#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s;
struct node{
    int l,r,len;
}ss[305];
bool vis[305];
int n;

int dfs(int index,int ll,int sum)
{
    vis[index]=true;
    int res=0;
    if(ll==0)
    {
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&ss[i].r==0)
            {
                res=max(res,dfs(i,ss[i].l,0));
                vis[i]=false;
            }
        }
        return sum+res;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&ss[i].r<=ll)
        {
            res=max(res,dfs(i,ll-ss[i].r+ss[i].l,sum+ss[i].r*2+ss[index].len));
            vis[i]=false;
        }
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    int ans=0;
    memset(ss,0,sizeof ss);
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int len=s.length();
        for(int j=0;j<len;j++)
        {
            if(s[j]=='(')
                ss[i].l++;
            else if(ss[i].l)
                ss[i].l--,ss[i].len+=2;
            else
                ss[i].r++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ss[i].r==0)
        {
            ans=max(ans,dfs(i,ss[i].l,ss[i].len));
            vis[i]=false;
        }
    }
    printf("%d\n",ans);
    return 0;
}
