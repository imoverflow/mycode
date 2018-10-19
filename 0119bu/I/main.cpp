#include <iostream>
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
const int N=200005;
int used[N];
int max_health[N];
int base_health[N];
int regen[N];
int n,m,bounty,increase,damage;
tuple<int,int,int>health_point[N];
map<int,int>cnt;
set<int>update[N];
map<long long,int>add;
map<long long,int>erase;
vector<pair<int,int> >event[N];
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&bounty,&increase,&damage);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&max_health[i],&base_health[i],&regen[i]);
        event[i].push_back(make_pair(0,base_health[i]));        //��ʼʱ����0�� Ѫ��Ϊbase_health��ʱ��
    }
    for(int i=0;i<m;i++)
    {
        int time,enemy,hp;
        scanf("%d%d%d",&time,&enemy,&hp);
        enemy--;
        event[enemy].push_back(make_pair(time,hp));           //ʱ��Ϊtime Ѫ��Ϊhp��ʱ��
    }
    for(int i=0;i<n;i++)
    {
        sort(event[i].begin(),event[i].end());               //��ʱ��Ϊ��һ�ؼ�������
    }
    if(increase>0)                                          //���⴦����Ի������Ǯ�����
    {
        for(int i=0;i<n;i++)
        {
            if(max_health[i]<=damage||(regen[i]==0&&event[i].back().second<=damage))
            {
                puts("-1");
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++)                                   //
    {
        auto &v=event[i];
        for(int j=0;j<v.size();j++)
        {
            pair<int,int>e=v[j];
            if(e.second>damage)
                continue;
            add[e.first]++;
            pair<int,int>q;
            if(j<v.size()-1)                        //��һ�¼�
                 q=v[j+1];
            else
                q=make_pair(2e9,0);
            long long delta=min(q.first-e.first-1,regen[i]==0?(int)2e9:(min(damage,max_health[i])-e.second)/regen[i]);  //ȡ��ǰ�¼�����һ�¼���ָ��¼�ȡ��Сֵ
            erase[e.first+delta]++;             //ɾ�����¼���ʱ��
        }
    }
    int alive=0;
    set<long long>timeline;
    for(auto v:add)
        timeline.insert(v.first);
    for(auto v:erase)
        timeline.insert(v.first);
    long long ans=0;
    for(auto v:timeline)                        //ɨ�����е��¼�����ʱ��
    {
        alive+=add[v];
        ans=max(ans,alive*(bounty+increase*(long long)1*v));
        alive-=erase[v];
    }
    printf("%lld",ans);
    return 0;
}
