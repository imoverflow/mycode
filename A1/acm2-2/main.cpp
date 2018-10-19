#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int a,b,c,d;
    int i,j,k,l;
    char s[51];
    int legal(char* t);
    while(scanf("%d",&a)!=EOF)
    {
        getchar();
        for(i=0;i<a;i++)
        {
            gets(s);
            if(legal(s)==0)
                printf("no\n");
                else
                printf("yes\n");
        }
    }
    return 0;
}

int legal(char* t)
{
    int i;
    if(!((t[0]>='A'&&t[0]<='Z')||(t[0]>='a'&&t[0]<='z')||t[0]=='_'))
    {
        return 0;
    }
    for(i=1;i<strlen(t);i++)
    {
        if(!((t[i]>=65&&t[i]<=90)||(t[i]>=97&&t[i]<=122)||t[i]=='_'))
    {
        return 0;
    }
    }
    return 1;
}
