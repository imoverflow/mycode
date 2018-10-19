#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int n,m;
vector<pair<int,int> >g[1005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(make_pair(b,c));
            g[b].push_back(make_pair(a,c));
        }
    }
    return 0;
}
