#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[100005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    char now=0;
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(now!=s[i])
        {
            if(now==0)
            {
                now=s[i];
                cnt++;
                continue;
            }
            printf("%c%d",now,cnt);
            now=s[i];
            cnt=1;
        }else{
            cnt++;
        }
    }
    printf("%c%d\n",now,cnt);
    return 0;
}
