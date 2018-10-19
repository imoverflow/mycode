#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[105][105]={0};
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
typedef pair<int ,int> pii;
queue<pii>q;
int n,m,k;
int bfs(pii z){
    s[z.first][z.second]=1;
    q.push(z);
    int cnt=0;
    while(q.size())
    {
        cnt++;
        pii p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=p.first+dx[i],yy=p.second+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[xx][yy]==0)
            {
                q.push(pii(xx,yy));
                s[xx][yy]=1;
            }
        }
    }
    return cnt;
}
int main()
{

    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==0)
        {
            for(int j=1;j<=m;j++)
            {
                s[b][j]=1;
            }
        }
        if(a==1)
        {
            for(int j=1;j<=n;j++)
            {
                s[j][b]=1;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]==0)
            {
                sum+=bfs(pii(i,j))/2;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
