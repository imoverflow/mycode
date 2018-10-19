#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n;
int d[200005];
int s[200005];
void bfs(int x)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        d[i]=INF;
    d[x]=0;
    q.push(x);
    while(q.size())
    {
        int p=q.front();
        q.pop();
        if(d[s[p]]>d[p]+1)
        {
            d[s[p]]=d[p]+1;
            q.push(s[p]);
        }
        if(p<n&&d[p+1]>d[p]+1)
        {
            d[p+1]=d[p]+1;
            q.push(p+1);
        }
        if(p>1&&p<=n&&d[p-1]>d[p]+1)
        {
            d[p-1]=d[p]+1;
            q.push(p-1);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
