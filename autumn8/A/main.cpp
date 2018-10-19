//#include <iostream>
//#include <set>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <stack>
//#include <stdio.h>
//#include <string>
//#include <cstring>
//#define INF 0x3f3f3f3f
//using namespace std;
//
//bool vis[129][129][129];
//char s[129][129][129];
//int bit[9];
//stack<char>ss;
//int V;
//void func() {
//	bit[0]=1;
//	for(int i = 1; i <= 8; i++)
//		bit[i] = bit[i-1] * 2;
//}
//
//int dfs(int x,int y,int z,int n)
//{
//    int a1,a2,a3,a4,a5,a6,a7,a8;
//    if(n==0)
//        return vis[x][y][z];
//    a1=dfs(x+bit[n-1], y+bit[n-1], z+bit[n-1],n-1);
//    a2=dfs(x, y+bit[n-1], z+bit[n-1],n-1);
//    a3=dfs(x, y, z+bit[n-1],n-1);
//    a4=dfs(x+bit[n-1], y, z+bit[n-1],n-1);
//    a5=dfs(x+bit[n-1], y+bit[n-1], z,n-1);
//    a6=dfs(x, y+bit[n-1], z,n-1);
//    a7=dfs(x, y, z,n-1);
//    a8=dfs(x+bit[n-1], y, z,n-1);
//    int res=a1+a2+a3+a4+a5+a6+a7+a8;
//    s[x+bit[n-1]][y+bit[n-1]][z+bit[n-1]]=(a1==0||a1==1)?a1:'*';
//    s[x][y+bit[n-1]][z+bit[n-1]]=(a2==0||a2==1)?a2:'*';
//    s[x][y][z+bit[n-1]]=(a3==0||a3==1)?a3:'*';
//    s[x+bit[n-1]][y][z+bit[n-1]]=(a4==0||a4==1)?a4:'*';
//    s[x+bit[n-1]][y+bit[n-1]][z]=(a5==0||a5==1)?a5:'*';
//    s[x+bit[n-1]][y+bit[n-1]][z]=(a6==0||a6==1)?a6:'*';
//    s[x][y+bit[n-1]][z]=(a7==0||a7==1)?a7:'*';
//    s[x+bit[n-1]][y][z]=(a8==0||a8==1)?a8:'*';
//    if(res==0)
//    {
//        return 0;
//    }else if(res==8)
//    {
//        return 1;
//    }else{
//        return -INF;
//    }
//}
void dfs1(int x,int y,int z,int n)
{
    if(n==0)
        return vis[x][y][z];
    a1=dfs(x+bit[n-1], y+bit[n-1], z+bit[n-1],n-1);
    a2=dfs(x, y+bit[n-1], z+bit[n-1],n-1);
    a3=dfs(x, y, z+bit[n-1],n-1);
    a4=dfs(x+bit[n-1], y, z+bit[n-1],n-1);
    a5=dfs(x+bit[n-1], y+bit[n-1], z,n-1);
    a6=dfs(x, y+bit[n-1], z,n-1);
    a7=dfs(x, y, z,n-1);
    a8=dfs(x+bit[n-1], y, z,n-1);
}
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    func();
//    while(t--)
//    {
//        while(!ss.empty())
//            ss.pop();
//        memset(vis,0,sizeof vis);
//        memset(s,0,sizeof s);
//        int n;
//        scanf("%d",&n);
//        int m;
//        V=n;
//        scanf("%d",&m);
//        for(int i=0;i<m;i++)
//        {
//            int a,b,c;
//            scanf("%d%d%d",&a,&b,&c);
//            vis[a][b][c]=true;
//        }
//        dfs(1,1,1,n);
////        printf("%d\n",ss.size());
//        while(!ss.empty())
//        {
//            printf("%c",ss.top());
//            ss.pop();
//        }
//        printf("\n");
//    }
//    return 0;
//}













struct N{
    int xx;
};


struct student{
    int num;
    N a;
}st[100];

st[0]
