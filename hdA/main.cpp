#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    char s[1005];
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        getchar();
        gets(s);
        int cou=0;
        if(s[strlen(s)-1]=='?')
            printf("-_-\n");
        else if(s[strlen(s)-1]=='.')
            printf("Orz\n");
        else if(s[strlen(s)-1=='!'])
        {
            for(int i=strlen(s)-1;i>=0;i--)
            {
                if(s[i]=='!')
                    cou++;
                else
                    break;
            }
            printf("W");
            for(int i=0;i<cou;i++)
                printf("o");
            printf("w!\n");
        }
    }
    return 0;
}
