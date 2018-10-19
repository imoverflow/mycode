#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[1005][1005];
bool vis[1005][1005];
int is[1005][1005];
int xx[]={0,0,1,-1},yy[]={1,-1,0,0};
int n,m;
struct node{
    int a,b,c;
};
vector<node>ans;
void bfs(int x1,int y1)
{
    queue<pair<int,int> >q;
    vis[x1][y1]=1;
    q.push(make_pair(x1,y1));
    while(q.size())
    {
        int a,b;
        pair<int,int>p=q.front();
        a=p.first,b=p.second;
        q.pop();
        int i=1;
        bool flag=false;
        while(s[a-i][b]=='*'&&s[a+i][b]=='*'&&s[a][b+i]=='*'&&s[a][b-i]=='*')
        {
            flag=true;
            is[a-i][b]=1;
            is[a+i][b]=1;
            is[a][b+i]=1;
            is[a][b-i]=1;
            is[a][b]=1;
            i++;
        }
        if(flag)
            ans.push_back(node{a,b,i-1});
        for(int i=0;i<4;i++)
        {
            int x=a+xx[i],y=b+yy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='*')
            {
                if(vis[x][y]==false)
                    q.push(make_pair(x,y));
                vis[x][y]=1;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*'&&!vis[i][j])
                bfs(i,j);
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*'&&is[i][j]!=1)
            {
                flag=false;
                goto label;
            }
        }
    }
    label:
    if(flag)
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
        }
    }else{
        printf("-1\n");
    }
    return 0;
}
