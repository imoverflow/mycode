#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
int weight[310][310];
bool visx[310],visy[310];
int match[310],lx[310],ly[310];
int nx,ny;
int n;
const int INF=INT_MAX;
bool findpath(int x)
{
    visx[x] = true;
    for(int y = 0 ; y < ny ; ++y)
    {
        if(!visy[y] && lx[x] + ly[y] == weight[x][y]) //y不在交错路中且edge(x,y)必须在相等子图中
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
    for(int x = 0 ; x < nx ; ++x)
    {
        while(true)
        {
            int delta=INF;
            memset(visx,0,sizeof(visx));//访问过X中的标记
            memset(visy,0,sizeof(visy));//访问过Y中的标记
            if(findpath(x))//找到了增广路，跳出继续寻找下一个
                break;
            else
            {
                for(int i = 0 ; i < nx ; ++i)
                {
                    if(visx[i])//i在交错路中
                    {
                        for(int j = 0 ; j < ny ; ++j)
                        {
                            if(!visy[j])//j不在交错路中，对应第二类边
                                delta = min(delta,lx[x] + ly[j] - weight[i][j]);
//                                delta=lx[i] + ly[j] - weight[i][j];
                        }
                    }
                }
                for(int i = 0 ; i < nx ; ++i)//增广路中xi - delta
                {
                    if(visx[i])
                        lx[i] -= delta;
                    if(visy[i])
                        ly[i] += delta;
                }
            }
//        cout<<"bug"<<endl;
        }
    }
    int ans=0;
    for(int i=0;i<ny;i++)
    {
        ans+=weight[match[i]][i];
    }
    return ans;
}
int main()
{
//    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(lx,0,sizeof lx);
        memset(ly,0,sizeof ly);
//        memset(weight,0,sizeof weight);
        memset(match,-1,sizeof match);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&weight[i][j]);
                lx[i]=max(lx[i],weight[i][j]);
            }
        }
        nx=ny=n;
        int p=KM();
        printf("%d\n",p);
    }
    return 0;
}
