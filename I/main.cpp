#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double dp[2009][2009];

int n, m;

double dfs(int a, int b){
    if(dp[a][b]!=-1)
        return dp[a][b];
    int cnt=0, flag[5];
    memset(flag, 0, sizeof flag);
    if(a>=4) cnt++, flag[0]=1;
    if(a>=3 && b>=1) cnt++, flag[1]=1;
    if(a>=2 && b>=2) cnt++, flag[2]=1;
    if(a>=1 && b>=3) cnt++, flag[3]=1;
    if(b>=4) cnt++, flag[4]=1;
    dp[a][b]=0;
    if(flag[0]) dp[a][b]+=1.0/cnt*dfs(a-4, b);
    if(flag[1]) dp[a][b]+=1.0/cnt*dfs(a-3, b-1);
    if(flag[2]) dp[a][b]+=1.0/cnt*dfs(a-2, b-2);
    if(flag[3]) dp[a][b]+=1.0/cnt*dfs(a-1, b-3);
    if(flag[4]) dp[a][b]+=1.0/cnt*dfs(a, b-4);
    return dp[a][b];


}

void solve(){

    for(int i=0; i<=n*4; i++){
        for(int j=0; j<=m*4; j++)
            dp[i][j]=-1;
    }
    dp[4][0]=0, dp[3][1]=0, dp[2][2]=0, dp[1][3]=0, dp[0][4]=1;
    double ans=dfs(n*4, m*4);
    printf("%.20f\n", ans);
}

int main()
{
    while(cin>>n>>m)
        solve();
    return 0;
}
