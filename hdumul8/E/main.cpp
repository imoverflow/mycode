#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[10][10];
void rotate_(int x,int y,char c)
{
    if(c=='C')
    {
        int t=s[x][y];
        s[x][y]=s[x+1][y];
        s[x+1][y]=s[x+1][y+1];
        s[x+1][y+1]=s[x][y+1];
        s[x][y+1]=t;
    }else{
        int t=s[x][y];
        s[x][y]=s[x][y+1];
        s[x][y+1]=s[x+1][y+1];
        s[x+1][y+1]=s[x+1][y];
        s[x+1][y]=t;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=3;i++)
        {
            char x[10];
            scanf("%s",x+1);
            for(int j=1;j<=3;j++)
            {
                s[i][j]=x[j]-'0';
            }
        }
        for(int i=0;i<n;i++){
            char x[10];
            scanf("%s",x);
            int a=x[0]-'0';
            if(a==1)
            {
                rotate_(1,1,x[1]);
            }else if(a==2)
            {
                rotate_(1,2,x[1]);
            }else if(a==3)
            {
                rotate_(2,1,x[1]);
            }else if(a==4)
            {
                rotate_(2,2,x[1]);
            }
        }
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                printf("%d",s[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
