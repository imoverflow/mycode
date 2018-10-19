#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
char a[100005];
char b[100005];
int fa[100005];
vector<pair<char,char> >v;
int Find(char c)
{
    return fa[c]==c?c:fa[c]=Find(fa[c]);
}
void Merge(char a,char b)
{
    int x=Find(a);
    int y=Find(b);
    if(x!=y)
    {
        v.push_back(make_pair(x,y));
        fa[x]=y;
    }
}
void init()
{
    for(int i=0;i<100005;i++)
    {
        fa[i]=i;
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    init();
    for(int i=0;i<n;i++)
    {
        Merge(a[i],b[i]);
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
    {
        printf("%c %c\n",v[i].first,v[i].second);
    }
    return 0;
}
