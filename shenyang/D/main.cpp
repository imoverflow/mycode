#include <bits/stdc++.h>
using namespace std;
#define Maxn 10010
#define INF 0x3f3f3f3f

struct node{
	int to,val;
	node() {}
	node(int a,int b)
	{
		to = a; val = b;
	}
};

vector<node> adj[Maxn],_adj[Maxn];

int n,m,k,T;
bool vis[Maxn];
int dis[Maxn];

void AddEdge(int x,int y,int val)
{
	adj[x].push_back(node(y,val));
	_adj[y].push_back(node(x,val));
}
priority_queue<int , vector<int> , greater<int> > q;
void Dijkstra(int s,int t)
{
	while(!q.empty()) q.pop();
//    memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++) vis[i] = false,dis[i] = INF;
	vis[t] = true; dis[t] = 0; q.push(t);

	int u,len;
	while(!q.empty())
	{
		u = q.top();  q.pop();
		len = _adj[u].size();
		for(int i=0;i<len;i++)
		{
			node v = _adj[u][i];
			if(dis[v.to] > dis[u] + v.val)
			{
				dis[v.to] = dis[u] + v.val;
				if(!vis[v.to])
				{
					q.push(v.to);
					vis[v.to] = true;
				}
			}
		}
		vis[u] = false;
	}
}

struct Anode{
	int h,g,id;
	Anode(int a,int b,int c) {h=a; g=b; id=c;}
	bool operator < (Anode a) const
	{
		return h+g > a.h+a.g;
	}
};

priority_queue<Anode> Q;

int Astar(int s,int t)
{
	while(!Q.empty()) Q.pop();
	Q.push(Anode(0,dis[s],s));

	int len,num;
	num = 0;
	while(!Q.empty())
	{
		Anode u = Q.top(); Q.pop();
		if(u.id==t) ++num;
		if(num>=k) return u.h;

		len = adj[u.id].size();
		for(int i=0;i<len;i++)
		{
			node v = adj[u.id][i];
			if(u.h+v.val<=T)
                Q.push(Anode(u.h+v.val,dis[v.to],v.to));
		}
	}

	return -1;
}

void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main()
{
//    cout<<INF<<endl;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<=n;i++)
            adj[i].clear(),_adj[i].clear();
		int s,e;
		read(s);
		read(e);
		read(k);
		read(T);
		for(int i=1;i<=m;i++)
		{
		    int a,b,c;
		    read(a);
		    read(b);
		    read(c);
			AddEdge(a,b,c);
		}
		if(s==e) k++;
		Dijkstra(s,e);
		if(dis[s]==INF){
            printf("Whitesnake!\n");
            continue;
		}
		int ans=Astar(s,e);
		if(ans<=T&&ans!=-1)
            printf("yareyaredawa\n");
        else
            printf("Whitesnake!\n");
	}
	return 0;
}
/*
7 8
1 6 3 64
1 2 1
2 7 3
7 3 5
2 3 2
3 6 4
3 4 8
4 5 16
5 2 32

2 2
1 2 2 15
1 2 5
2 1 4

3 2
1 3 2 10000
1 2 1
2 3 2

*/
