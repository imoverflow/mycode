#include <bits/stdc++.h>

using namespace std;

char s[150009];
int vis[150009];
bool ban[150009];
//vector<int>x;
int n,ma;
vector<int> g[150009];
void init()
{
    memset(vis,-1,sizeof vis);
    memset(ban,0,sizeof ban);
    ma='0';
    for(int i=0;i<n;i++)
    {
        g[i].push_back(1ll*i*i%n);
        ma=max(ma,s[i]);
    }
}
struct node{
    int step,cur;
    bool operator <(const node &a)
    {
        if(step!=a.step) return step>a.step;
        else return s[cur]>s[a.cur];
    }
}x[150009];
void solve()
{
    priority_queue<node>q;
    for(int i=0;i<n;i++)
    {
        if(s[i]==ma)
        {
            q.push(make_pair(i,i));
            vis[i]=true;
        }
    }
    string ans;
    ans.resize(n,char('0'-1));
    while(q.size())
    {
        auto p=q.top();
        if(ans[p.step]>s[p.cur]) continue;
        if(vis[p.step]==true) continue;
        if(p.step>=n) continue;
        ans[p.step]=s[p.cur];

        q.push(node(p.step+1,g[p.cur][0]));
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        init();
    }
    return 0;
}
