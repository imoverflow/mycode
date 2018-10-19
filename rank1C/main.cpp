#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define INF 100000000
using namespace std;
int n,k;

int pre[100050];
bool vis[100050];
void bfs()
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<100005;i++)
    {
        pre[i]=INF;
    }
    q.push(n);
    pre[n]=0;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        if(vis[t]==true)
            continue;
        if(t==k)
            break;
        if(vis[t+1]==false&&t<100000)
        {
            q.push(t+1);
            pre[t+1]=min(pre[t+1],pre[t]+1);
            vis[t]=true;
        }
        if(vis[t-1]==false&&t>=1)
        {
            q.push(t-1);
            pre[t-1]=min(pre[t-1],pre[t]+1);
            vis[t]=true;
        }
        if(vis[2*t]==false&&t<=50000)
        {
            q.push(2*t);
            pre[2*t]=min(pre[2*t],pre[t]+1);
            vis[t]=true;
        }
    }
    return;
}
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        bfs();
        printf("%d\n",pre[k]);
    }

    return 0;
}
