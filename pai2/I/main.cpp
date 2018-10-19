#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int app[105];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&app[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    return 0;
}
