#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>g[200005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}
