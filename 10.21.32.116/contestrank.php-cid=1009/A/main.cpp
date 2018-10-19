#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+9;

int a1[N],a2[N],b1[N],b2[N];
set<int>s;
vector<int>g[N];
bool vis[N];
bool isdel[N];
int dfs(int x)
{
    int i;
    for(i=x;;i=a1[i])
    {
        if(!vis[i])
        {
            vis[i]=true;
        }else{
            break;
        }
    }
    return b1[i];
}
int rdfs(int x,int &num)
{
    int i;
    for(i=x;;i=b1[i])
    {
        if(!vis[i])
        {
            num++;
            vis[i]=true;
        }else{
            break;
        }
    }
    return a1[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
        a2[i]=a1[i];
        b1[a1[i]]=i;
        b2[a1[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
    }
    int minans=0,maxans=0;
    while(s.size())
    {
        int x=*s.begin();
        if(isdel[x]||isdel[b1[x]]&&isdel[a1[x]])
        {
            s.erase(x);
            continue;
        }
        int res=0;
        memset(vis,0,sizeof vis);
        int leaf1=dfs(x);
        memset(vis,0,sizeof vis);
        int leaf2=rdfs(x,res);
//        minans+=link.size()/2;
        maxans+=res-1;
        for(int i=leaf1;i!=leaf2;i=b1[i])
        {
            isdel[i]=true;
            s.erase(i);
        }
        cout<<s.size()<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
        isdel[i]=false;
    }
    while(s.size())
    {
        int x=*s.begin();
        if(isdel[x]||isdel[b1[x]]&&isdel[a1[x]])
        {
            s.erase(x);
            continue;
        }
        int res=0;
        int leaf1=dfs(x);
        int leaf2=rdfs(x,res);
        minans+=res/2;
        bool flag=false;
        for(int i=leaf2;i!=leaf1;i=a1[i])
        {
            if(flag)
            {
                s.erase(i);
                isdel[i]=true;
            }
            flag=!flag;
        }
    }
    printf("%d %d\n",minans,maxans);
    return 0;
}
