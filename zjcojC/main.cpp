#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <set>
using namespace std;

char s[100],key[100];
int main()
{
    while(scanf("%s %s",s,key)!=EOF){
        int len1=strlen(s);
        int len2=strlen(key);
        for(int i=0;i<len1;i++)
        {
            printf("%c",'a'+(key[i%len2]-'a'+s[i]-'a')%26);
        }
        printf("\n");
    }
    return 0;
}
