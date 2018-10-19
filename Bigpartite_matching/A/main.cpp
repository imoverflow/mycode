#include <iostream>
#include <bits/stdc++.h>
#define MAX_V 100
using namespace std;

/**���ƥ���㷨���������㷨**/
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
/**����ƥ��KM�㷨����Ȩ����ͼ**/
bool findpath(x)
{
    visx[x] = true;
    for(int y = 1 ; y <= ny ; ++y)
    {
        if(!visy[y] && lx[x] + ly[y] == weight(x,y)) //y���ڽ���·����edge(x,y)�����������ͼ��
        {
            visy[y] = true;
            if(match[y] == -1 || findpath(match[y]))//���y��Ϊƥ����ߴ�y��match���������ҵ�һ��ƥ���
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
            memset(visx,false,sizeof(visx));//���ʹ�X�еı��
            memset(visy,false,sizeof(visy));//���ʹ�Y�еı��
            if(findpath(x))//�ҵ�������·����������Ѱ����һ��
                break;
            else
            {
                for(int i = 1 ; i <= nx ; ++i)
                {
                    if(visx[i])//i�ڽ���·��
                    {
                        for(int j = 1 ; j <= ny ; ++j)
                        {
                            if(visy[j])//j���ڽ���·�У���Ӧ�ڶ����
                                delta = Min(delta,lx[i] + ly[y] - weight(i,j))
                        }
                    }
                }
                for(int i = 1 ; i <= nx ; ++i)//����·��xi - delta
                    if(visx[i])
                        lx[i] -= delta;
                for(int j = 1 ; j <= ny ; ++j)//����·��yj + delta
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
