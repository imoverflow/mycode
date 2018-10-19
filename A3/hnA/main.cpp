#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int a;
    char s[3000];
    char s1[3000];
    scanf("%d",&a);
    scanf("%s",s);
    if(a%2==0)
    {
        for(int i=a/2-1,j=0;i>=0;i--,j+=2)
        {
            s1[i]=s[j];
            s1[a-i-1]=s[j+1];
        }
    }else{
        for(int i=a/2-1,j=1;i>=0;i--,j+=2)
        {
            s1[i]=s[j];
            s1[a-i-1]=s[j+1];
        }
        s1[a/2]=s[0];
    }
    for(int i=0;i<a;i++)
    {
        printf("%c",s1[i]);
    }

}

