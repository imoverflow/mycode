#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int dp[105][105];
    char s[1005];
    while(scanf("%s",&s)!=EOF)
    {
        if(strcmp(s,"end")==0)
            break;
        memset(dp,0,sizeof(dp));
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')
                    dp[i][j]=dp[i+1][j-1]+2;
                else

            }
        }
    }
    return 0;
}
