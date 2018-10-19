#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
//const int Max_M = 1e3;
//int ans[Max_M];
//int cnt=0;
//bool vis[2*Max_M];
//vector<int> edge[Max_M];
///*
//    edge 链式前进星
//*/
///*构建链式前进星前需要sort一次*/
//int head[Max_M*2];
//struct Edge{
//    int to;
//    int next;
//}edge[Max_M*2];
//
//bool cmp(const Edge &a,const Edge &b)
//{
//    return
//}
//void build_link()
//{
//    sort(edge,edge+Max_M,cmp);
//    for(int k=0;k<Max_M;k++)
//    {
//        edge[k].to=j;
//        edge[k].next=head[i];
//        head[i]=k;
//    }
//}
//
void dfs(int now)
{
    for(int k=edge[now][i];k!=0;k=edge[k].next)
    {
        if(!vis[k])
        {
            vis[k]=true;
            vis[k^1]=true;
            dfs(edge[k].to);
            ans[cnt++]=k;
        }
    }
}
int head[10]={-1};
struct Edge{
    int to,next;
}s[10];
int main()
{
    memset(s,0,sizeof s);
    for(int i=1;i<=5;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s[i].to=b;
        s[i].next=head[a];
        head[a]=i;
    }
    for(int i=1;i<=5;i++)
    {
        for(int k=head[i];k!=0;k=s[k].next)
        {
            cout<<i<<" "<<s[k].to<<endl;
        }
    }
    return 0;
}
