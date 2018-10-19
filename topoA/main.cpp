#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>g[505];
int degree[505];
int ans[505];
bool used[505];
void topo(int n)
{
    int k=0;
    memset(degree,0,sizeof(int));
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            degree[g[i][j]]++;
        }
    }
    queue<int>q;
    while(k!=n)
    {

    for(int j=1;j<=n;j++)
    {
        if(degree[j]==0&&!used[j])
        {
           // q.push(j);
            ans[k++]=j;
            used[j]=true;
            for(int i=0;i<g[j].size();i++)
            {
                degree[g[j][i]]--;
            }
            break;
//            while(q.size())
//            {
//                int qq=q.front();
//                q.pop();
//                ans[k++]=qq;
//                for(int i=0;i<g[qq].size();i++)
//                {
//                    degree[g[qq][i]]--;
//                    if(degree[g[qq][i]]==0)
//                    {
//                        q.push(g[qq][i]);
//                        used[g[qq][i]]=true;
//                    }
//                }
//            }
        }
    }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,0,sizeof g);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        memset(ans,0,sizeof(ans));
        topo(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",ans[i]);
            else
                printf(" %d",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
