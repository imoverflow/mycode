#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[5][5];
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    int flag=1;
    for(int i=0;i<4;i++)
    {
        if(s[i][3]==1)
        {
            if(!(s[i][0]==0&&s[i][1]==0&&s[i][2]==0&&s[(i+1)%4][0]==0&&s[(i+2)%4][1]==0&&s[(i+3)%4][2]==0))
                flag=0;
        }
    }
    if(flag)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
