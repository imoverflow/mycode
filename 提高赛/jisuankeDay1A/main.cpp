#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[50][50];
int ans=0;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        memset(s,0,sizeof s);
        ans=0;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            s[a+3][b+3]=1;
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
        }
        if(s[0][0]&&s[0][3]&&s[0][6])
            ans++;
        if(s[0][0]&&s[3][0]&&s[6][0])
            ans++;
        if(s[6][0]&&s[6][3]&&s[6][6])
            ans++;
        if(s[0][6]&&s[3][6]&&s[6][6])
            ans++;
        if(s[0][3]&&s[1][3]&&s[2][3])
            ans++;
        if(s[4][3]&&s[5][3]&&s[6][3])
            ans++;
        if(s[3][0]&&s[3][1]&&s[3][2])
            ans++;
        if(s[3][4]&&s[3][5]&&s[3][6])
            ans++;
        if(s[1][1]&&s[1][3]&&s[1][5])
            ans++;
        if(s[5][1]&&s[5][3]&&s[5][5])
            ans++;
        if(s[1][1]&&s[3][1]&&s[5][1])
            ans++;
        if(s[1][5]&&s[3][5]&&s[5][5])
            ans++;
        if(s[2][2]&&s[3][2]&&s[4][2])
            ans++;
        if(s[2][4]&&s[3][4]&&s[4][4])
            ans++;
        if(s[2][2]&&s[2][3]&&s[2][4])
            ans++;
        if(s[4][2]&&s[4][3]&&s[4][4])
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}
