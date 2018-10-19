//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<cmath>
//using namespace std;
//
//const int VN = 105;
//const int INF = 0x7fffffff;
//
//template<typename Type>
//class Directed_MST{
//public:
//    void init(int _n){
//        n=_n;
//        ans = 0;
//        memset(vis, 0, sizeof(vis));
//        memset(inc, 0, sizeof(inc));
//        for(int i=0; i<=n; ++i){
//            w[i][i] = INF;
//            for(int j=i+1; j<=n; ++j)
//                w[i][j]=w[j][i]=INF;
//        }
//    }
//    void insert(int u, int v, Type _w){
//        if(w[u][v]>_w) w[u][v] = _w;
//    }
//    Type directed_mst(int u){
//        //==  ����1�� �ж��ܷ��γ���С����ͼ��ֱ��dfs����
//        dfs(u);
//        for(int i=1; i<=n; ++i)
//            if(!vis[i]) { return -1; }
//
//        //== ��������γ���С����ͼ������
//        memset(vis, 0, sizeof(vis));
//        while(true){
//            //== 1. ����Сǰ����
//            for(int i=1; i<=n; ++i)if(i!=u&&!inc[i]){          //����root���Ҹõ�û�б�����
//                w[i][i]=INF, pre[i] = i;
//                for(int j=1; j<=n; ++j)if(!inc[j] && w[j][i]<w[pre[i]][i]){
//                    pre[i] = j;
//                }
//            }
//            //== 2.�ж��Ƿ��л�
//            int i;
//            for(i=1; i<=n; ++i){
//                if(i!=u&&!inc[i]){
//                    int j=i, cnt=0;
//                    while(j!=u && pre[j]!=i && cnt<=n)
//                        j=pre[j], ++cnt;     //O(n);
//                    if(j==u || cnt>n) continue; //û�ҵ�
//                    break;
//                }
//            }
//
//            //== û���ҵ���,�õ���
//            if(i>n){
//                for(int i=1; i<=n; ++i)if(i!=u && !inc[i]) ans+=w[pre[i]][i];
//                return ans;
//            }
//            //==  �л�����������
//            int j=i;
//            memset(vis, 0, sizeof(vis));
//            do{
//                ans += w[pre[j]][j], j=pre[j], vis[j]=inc[j]=true;
//            }while(j!=i);
//            inc[i] = false; // �������˵�i����i��Ȼ����
//
//            //==  ����
//            for(int k=1; k<=n; ++k)if(vis[k]){ // �ڻ��е��
//                for(int j=1; j<=n; ++j)if(!vis[j]){  // ���ڻ��еĵ�
//                    if(w[i][j] > w[k][j]) w[i][j] = w[k][j];
//                    if(w[j][k]<INF && w[j][k]-w[pre[k]][k] < w[j][i])
//                        w[j][i] = w[j][k] - w[pre[k]][k];
//                }
//            }
//        }
//        return ans;
//    }
//
//private:
//    // �Ӹ�������һ�飬�ж��Ƿ������С����ͼ
//    void dfs(int u){
//        vis[u] = true;
//        for(int i=1; i<=n; ++i)if(!vis[i]&&w[u][i]<INF){
//            dfs(i);
//        }
//    }
//
//private:
//    Type ans;         // �����
//    int n;            // ������
//    int pre[VN];      // Ȩֵ��С��ǰ����
//    bool vis[VN];     // ���ڻ��л����ڻ���
//    bool inc[VN];     // �õ��Ƿ�ɾ���ˣ�������
//    Type w[VN][VN];   // ͼ
//};
//
//
//Directed_MST<double>G;
//double x[VN],y[VN];
//inline double getDist(double x1,double y1,double x2,double y2){
//    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
//}
//
//int main(){
//    int n,m;
//    while(~scanf("%d%d",&n,&m)){
//        G.init(n);
//        for(int i=1; i<=n; ++i)
//            scanf("%lf%lf",&x[i],&y[i]);
//        for(int i=0; i<m; ++i){
//            int a,b;
//            scanf("%d%d",&a,&b);
//            if(a==b)continue;
//            G.insert(a,b,getDist(x[a],y[a],x[b],y[b]));
//        }
//        double ans = G.directed_mst(1);
//        if(ans < 0) puts("poor snoopy");
//        else printf("%.2f\n", ans);
//    }
//    return 0;
//}
#include <stdio.h>
#include <cstring>
#include <math.h>
//poj 3164
using namespace std;
const int INF=0x3f3f3f3f;
double d[200][200];
int pre[200],id[200],vis[200],in[200],inc[200];
int n,m;
void dfs(int u)
{
	vis[u] = true;
	for(int i=1; i<=n; ++i)if(!vis[i]&&d[u][i]<INF)
	{
		dfs(i);
	}
}

double MST(int u)
{
	double ans=0;
    dfs(u);
    for(int i=1; i<=n; ++i)
            if(!vis[i]) { return -1; }

        memset(vis, 0, sizeof(vis));
        while(true){
            //== 1. ����Сǰ����
            for(int i=1; i<=n; ++i)if(i!=u&&!inc[i]){          //����root���Ҹõ�û�б�����
                d[i][i]=INF, pre[i] = i;
                for(int j=1; j<=n; ++j)if(!inc[j] && d[j][i]<d[pre[i]][i]){
                    pre[i] = j;
                }
            }
            //== 2.�ж��Ƿ��л�
            int i;
            for(i=1; i<=n; ++i){
                if(i!=u&&!inc[i]){
                    int j=i, cnt=0;
                    while(j!=u && pre[j]!=i && cnt<=n)
                        j=pre[j], ++cnt;     //O(n);
                    if(j==u || cnt>n) continue; //û�ҵ�
                    break;
                }
            }

            //== û���ҵ���,�õ���
            if(i>n){
                for(int i=1; i<=n; ++i)if(i!=u && !inc[i]) ans+=d[pre[i]][i];
                return ans;
            }
            //==  �л�����������
            int j=i;
            memset(vis, 0, sizeof(vis));
            do{
                ans += d[pre[j]][j], j=pre[j], vis[j]=inc[j]=true;
            }while(j!=i);
            inc[i] = false; // �������˵�i����i��Ȼ����

            //==  ����
            for(int k=1; k<=n; ++k)if(vis[k]){ // �ڻ��е��
                for(int j=1; j<=n; ++j)if(!vis[j]){  // ���ڻ��еĵ�
                    if(d[i][j] > d[k][j]) d[i][j] = d[k][j];
                    if(d[j][k]<INF && d[j][k]-d[pre[k]][k] < d[j][i])
                        d[j][i] = d[j][k] - d[pre[k]][k];
                }
            }
        }
        return ans;
}
double dis(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void add_edge(int from,int to,double w)
{
    if(d[from][to]>w) d[from][to]=w;
}
double x[200],y[200];
void init()
{
    memset(vis,0,sizeof vis);
    memset(inc,0,sizeof inc);
    for(int i=0; i<=n; ++i){
        d[i][i] = INF;
        for(int j=i+1; j<=n; ++j)
            d[i][j]=d[j][i]=INF;
    }
}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==b) continue;
            add_edge(a,b,dis(x[a],y[a],x[b],y[b]));
        }
        double ans=MST(1);
        if(ans<0) printf("poor snoopy\n");
        else printf("%.2f\n",ans);
    }
    return 0;
}
