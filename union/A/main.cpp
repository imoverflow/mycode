#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fa[100];
int height[100];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        fa[i]=i;
        height[i]=0;
    }
}
int _find(int v)
{
    if(fa[v]==v) return v;
    else return fa[v]=_find(fa[v]);
}

void _union(int v,int u)
{
    int x=_find(v);
    int y=_find(u);
    if(x==y)
        return;
    if(height[x]<height[y])
    {
        fa[x]=y;
    }else{
        fa[y]=x;
        if(height[x]==height[y])
            height[x]++;
    }
}

int main()
{

    return 0;
}
