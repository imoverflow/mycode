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
        if(!visy[y] && lx[x] + ly[y] == weight[x][y]) //y���ڽ���·����edge(x,y)�����������ͼ��
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
    for(int x = 0 ; x < nx ; ++x)
    {
        while(true)
        {
            int delta=INF;
            memset(visx,0,sizeof(visx));//���ʹ�X�еı��
            memset(visy,0,sizeof(visy));//���ʹ�Y�еı��
            if(findpath(x))//�ҵ�������·����������Ѱ����һ��
                break;
            else
            {
                for(int i = 0 ; i < nx ; ++i)
                {
                    if(visx[i])//i�ڽ���·��
                    {
                        for(int j = 0 ; j < ny ; ++j)
                        {
                            if(!visy[j])//j���ڽ���·�У���Ӧ�ڶ����
                                delta = min(delta,lx[x] + ly[j] - weight[i][j]);
//                                delta=lx[i] + ly[j] - weight[i][j];
                        }
                    }
                }
                for(int i = 0 ; i < nx ; ++i)//����·��xi - delta
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
