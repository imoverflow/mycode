#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int a[505];
int b[505];
int l,n,m;
int c[505];
set<int>g;
void check()
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<n;j++)
        {
           g.insert(a[i]+b[j]);
        }
    }
}
int main()
{
    int cas=1;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        g.clear();
        for(int i=0;i<l;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
        }
        int s;
        check();
        scanf("%d",&s);
        printf("Case %d:\n",cas++);
        for(int i=0;i<s;i++)
        {
            int x;
            scanf("%d",&x);
            bool flag=false;
            for(int i=0;i<m;i++)
            {
                if(g.find(x-c[i])!=g.end())
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
