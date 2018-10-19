#include <bits/stdc++.h>

using namespace std;
int n,m,r,k;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
long long cal(int x,int y)
{
    int x1=min(n,x+r)-max(x+1,r)+1;  //右下角x值-左上角x值
    int y1=min(m,y+r)-max(y+1,r)+1;  //右下角y值-左上角y值
	return (long long)1*x1*y1;
}
struct cmp
{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b)const
    {
        return cal(a.first,a.second)<cal(b.first,b.second);
    }
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q;
int main()
{
    cin>>n>>m>>r>>k;
    set<pair<int,int> >s;
    s.emplace(n/2,m/2);
    q.emplace(n/2,m/2);
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        int a,b;
        tie(a,b)=q.top();
        q.pop();
        ans+=cal(a,b);
        for(int j=0;j<4;j++)
        {
            int xx=a+dx[j],yy=b+dy[j];
            if(xx<0||xx>=n||yy<0||yy>=m)
                continue;
            if(s.count(make_pair(xx,yy)))
                continue;
            q.emplace(xx,yy);
            s.emplace(xx,yy);
        }
    }
    printf("%.12f",(double)ans/(n-r+1)/(m-r+1));
    return 0;
}
