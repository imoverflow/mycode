#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
const int maxm=200010;
int n,m,edgecnt,head[maxn];
struct edge{
    int v, next;
}edge[maxm*2];
struct link{
    int pre,next;
}line[maxn];
void del(int x){
    line[line[x].pre].next=line[x].next;
    line[line[x].next].pre=line[x].pre;
}
void init(){
    memset(head,-1,sizeof(head));
    edgecnt=0;
}
void addedge(int u,int v){
    edge[edgecnt].v=v;
    edge[edgecnt].next=head[u];
    head[u]=edgecnt++;
}
bool vis1[maxn],vis2[maxn];
int scc[maxn],scccnt;
void bfs(){
    queue <int> q;
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    while(line[0].next){
        int now = line[0].next, curscc = 1;
        del(now);
        q.push(now);
        vis2[now] = 1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i= head[u];~i;i = edge[i].next)
                vis1[edge[i].v] = 1;
            for(int i= line[0].next;i;i = line[i].next){
                if(!vis1[i]&&!vis2[i]){
                    vis2[i]=1;
                    q.push(i);
                    curscc++;
                    del(i);
                }
            }
            for(int i=head[u];~i;i=edge[i].next)
                vis1[edge[i].v]=0;
        }
        scc[++scccnt]=curscc;
    }
}
int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    for(int i=1;i<=n;i++){
        line[i-1].next=i; line[i].pre=i-1;
    }
    line[n].next = 0;
    bfs();
    sort(scc+1,scc+scccnt+1);
    printf("%d\n",scccnt);
    for(int i=1;i<scccnt;i++)
        printf("%d ", scc[i]);
    printf("%d", scc[scccnt]);
    return 0;
}
