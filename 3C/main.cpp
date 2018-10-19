#include <iostream>
#include <stdio.h>
using namespace std;
int s[3]={0};
int res[3]={0};
void dfs(int b,int g,int r)
{
    if(res[0]&&res[1]&&res[2])
        return;
    if(b+g+r<2)
    {
        if(b==1)
            res[0]=1;
        if(g==1)
            res[1]=1;
        if(r==1)
            res[2]=1;
        return;
    }
    if(b>=2) dfs(b-1,g,r);
    if(g>=2) dfs(b,g-1,r);
    if(r>=2) dfs(b,g,r-1);
    if(b>=1&&g>=1) dfs(b-1,g-1,r+1);
    if(b>=1&&r>=1) dfs(b-1,g+1,r-1);
    if(r>=1&&g>=1) dfs(b+1,g-1,r-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    char t;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&t);
        if(t=='B')
            s[0]++;
        if(t=='G')
            s[1]++;
        if(t=='R')
            s[2]++;
    }
    if(s[0]>2)
        s[0]=2;
    if(s[1]>2)
        s[1]=2;
    if(s[2]>2)
        s[2]=2;
    dfs(s[0],s[1],s[2]);
    if(res[0]) printf("B");
    if(res[1]) printf("G");
    if(res[2]) printf("R");
    return 0;
}
