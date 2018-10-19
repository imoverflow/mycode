#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int le[500]={0};
    char s1[100];
    char s2[100];
    char s[10005];
    scanf("%s%s%s",s1,s2,s);
    int len=strlen(s1);
    for(int i=0;i<len;i++)
    {
        le[s1[i]]=s2[i];
    }
    int len1=strlen(s);
    for(int i=0;i<len1;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            printf("%c",le[s[i]]);
        }else if(s[i]>='A'&&s[i]<='Z')
        {
            printf("%c",toupper(le[s[i]-'A'+'a']));
        }else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
