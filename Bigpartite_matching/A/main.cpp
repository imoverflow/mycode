#include <iostream>
#include <bits/stdc++.h>
#define MAX_V 100
using namespace std;

/**最大匹配算法，匈牙利算法**/
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

int bipartite_mathcing(){
    int res=0;
    memset(match ,-1,sizeof match);
    for(int v=0;v<V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof used);
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
/**********************************************************************************************************/
/**完美匹配KM算法，带权二分图**/
bool findpath(x)
{
    visx[x] = true;
    for(int y = 1 ; y <= ny ; ++y)
    {
        if(!visy[y] && lx[x] + ly[y] == weight(x,y)) //y不在交错路中且edge(x,y)必须在相等子图中
        {
            visy[y] = true;
            if(match[y] == -1 || findpath(match[y]))//如果y还为匹配或者从y的match还能另外找到一条匹配边
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int KM()
{
    for(int x = 1 ; x <= nx ; ++x)
    {
        while(true)
        {
            memset(visx,false,sizeof(visx));//访问过X中的标记
            memset(visy,false,sizeof(visy));//访问过Y中的标记
            if(findpath(x))//找到了增广路，跳出继续寻找下一个
                break;
            else
            {
                for(int i = 1 ; i <= nx ; ++i)
                {
                    if(visx[i])//i在交错路中
                    {
                        for(int j = 1 ; j <= ny ; ++j)
                        {
                            if(visy[j])//j不在交错路中，对应第二类边
                                delta = Min(delta,lx[i] + ly[y] - weight(i,j))
                        }
                    }
                }
                for(int i = 1 ; i <= nx ; ++i)//增广路中xi - delta
                    if(visx[i])
                        lx[i] -= delta;
                for(int j = 1 ; j <= ny ; ++j)//增广路中yj + delta
                    if(visy[j])
                        ly[j] += delta;
            }
    }
    int ans=0;
    for(int i=1;i<=ny;i++)
    {
        ans+=weight(i,i);
    }
    return ans;
}
/*********************************************************************************************************************************/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
