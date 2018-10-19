#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef pair<int,int> P;
const int MAXN=200100;
const int MAXM=200010;
vector<int>s;
struct Edge{
    int to,next;
}edge[MAXM];

int head[MAXN],tot,low[MAXN],dfn[MAXN],Stack[MAXN],belong[MAXN],index,top,scc;  //强连通分量的个数
bool instack[MAXN];
int num[MAXN];

void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void Tarjan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        }else if(instack[v]&&low[u]>low[v])
        {
            low[u]=dfn[v];
        }
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            instack[v]=false;
            s.push_back(v);
            belong[v]=scc;
            num[scc]++;
        }while(v!=u);
    }
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(num,0,sizeof(num));
    index=scc=top=0;
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i])
        {
            Tarjan(i);
        }
    }
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
set<P>ss;
vector<P>p;
bool cmp(P a,P b)
{
    return a.second<b.second;
}
int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        ss.clear();
        p.clear();
        scanf("%d%d",&n,&m);
//        if(n==0&&m==0) break;
        init();
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            ss.insert(P(a,b));
        }
//        printf("______________________\n");
//        for(int i=0;i<ss.size();i++)
//        {
//            printf("%d %d\n",(*it).first,(*it).second);
//            it++;
//        }
//        printf("______________________\n");
        solve(n);
        for(int i=0;i<s.size();i++)
        {
            p.push_back(P(s[i],dfn[s[i]]));
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<n-1;i++)
        {
            ss.erase(P(p[i].first,p[i+1].first));
            ss.erase(P(p[i+1].first,p[i].first));
        }
        ss.erase(P(p[0].first,p[n-1].first));
        ss.erase(P(p[n-1].first,p[0].first));
        set<P>::iterator it=ss.begin();
//        for(int i=0;i<ss.size();i++)
//        {
//            printf("%d %d\n",(*it).first,(*it).second);
//            it++;
//        }
//        printf("____________________________");
//        for(int i=0;i<n;i++)
//        {
//            printf("%d %d\n",p[i].first,p[i].second);
//        }
//        printf("____________________________");
        for(int i=0;i<m-2*n;i++)
        {
            printf("%d %d\n",(*it).first,(*it).second);
            it++;
        }
//        if(scc==1)
//        {
//            printf("Yes\n");
//        }else{
//            printf("No\n");
//        }
    }
    return 0;
}
/*
100
5 11
1 4
4 1
4 2
2 3
3 2
2 5
5 2
2 4
4 3
3 5
5 3
*/
