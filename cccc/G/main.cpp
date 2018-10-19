#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

char s[100005];
stack<char>ss;
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(ss.empty())
        {
            if(s[i]=='A')
                ss.push('A');
            else{
                printf("Nao\n");
                return 0;
            }
        }else{
            char t=ss.top();
            if(s[i]=='B'&&t=='A')
                ss.pop();
            else if(s[i]=='A'){
                ss.push('A');
            }else{
                printf("Nao\n");
                return 0;
            }
        }
    }
    if(ss.size())
        printf("Nao\n");
    else
        printf("Sim\n");
    return 0;
}
