#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

pair<long long,long long> dp[1000][1000];
int fun(int a,int b)
{
    if(dp[a][b].first!=INF)
    {
        return dp[i][j].first;
    }
}
int main()
{
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j].first=INF;
            dp[i][j].second=INF;
        }
    }
    return 0;
}
