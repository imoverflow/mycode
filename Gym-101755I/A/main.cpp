#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dep;
int dis[1030][1030];
int fa[1030];
int n;
int leaf1,leaf2,root;

int getdis(int x,int y)  //保存距离
{
    if(dis[x][y]==-1)
    {
        printf("? %d %d\n",x,y);
        fflush(stdout);
        scanf("%d",&dis[x][y]);
    }
    return dis[y][x]=dis[x][y];
}
//     当前节点    子树的节点    叶子1  叶子2   子树深度
void dfs(int now,vector<int> &x,int l,int r,int depth)
{
    if(now==l||now==r||depth==0) return;
    vector<int> vl;
    vector<int> vr;
    int rot1,rot2;
    int lf1=-1,lf2=-1;
    for(int i=0;i<x.size();i++)
    {
        int d1=getdis(x[i],l),d2=getdis(x[i],r);
        if(d1==(depth-1)*2&&d2==depth*2)   //找到了另外一片叶子
        {
            lf1=x[i];
        }
        if(d2==(depth-1)*2&&d1==depth*2)
        {
            lf2=x[i];
        }
        if(d1<d2)
        {
            if(d1==depth-1&&d2==depth+1)
            {
                rot1=x[i];            //左子树的根
                fa[rot1]=now;
            }else
                vl.push_back(x[i]);   //左子树

        }else if(d1>d2){
            if(d1==depth+1&&d2==depth-1)
            {
                rot2=x[i];            //右子树的根
                fa[rot2]=now;
            }else
                vr.push_back(x[i]);  //右子树
        }
    }
    if(lf1!=-1)
        dfs(rot1,vl,l,lf1,depth-1);
    else
        fa[lf1]=now;
    if(lf2!=-1)
        dfs(rot2,vr,r,lf2,depth-1);
    else
        fa[lf2]=now;
}
vector<int> x;
int main()
{
    //freopen("in.txt","r",stdin);
    memset(dis,-1,sizeof dis);
    memset(fa,-1,sizeof fa);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
    if(n==1)
    {
        printf("! 0");
        return 0;
    }
    dep=sizeof(int)*8-__builtin_clz(n);
    int temp=0;
    for(int i=2;i<=n;i++)               //两次for找根节点
    {
        int d=getdis(1,i);
        if(d>temp)
        {
            temp=d;
            leaf1=i;
        }
    }
    temp=0;
    for(int i=1;i<=n;i++)
    {
        if(i==leaf1) continue;
        int d=getdis(leaf1,i);
        if(d>temp)
        {
            temp=d;
            leaf2=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==leaf1||i==leaf2) continue;
        int d1=getdis(i,leaf1),d2=getdis(i,leaf2);
        if(d1==dep-1&&d2==dep-1)
        {
            root=i;
            break;
        }
    }
    fa[root]=0;
    for(int i=1;i<=n;i++)
    {
        if(i==root) continue;
        x.push_back(i);
    }
    dfs(root,x,leaf1,leaf2,dep-1);
    printf("!");
    for(int i=1;i<=n;i++)
    {
        printf(" %d",fa[i]);
    }
    fflush(stdout);
    return 0;
}
