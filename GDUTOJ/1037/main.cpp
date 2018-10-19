#include <iostream>
#include <stdio.h>
using namespace std;

char s[505][505];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",&s[i]);
        }
        int flag=1;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(s[i][j]!=s[j][i])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
