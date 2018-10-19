#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char x[1000006];
int nxt[1000006];
void kmp_pre(int m)        //两种处理方法
{
    int i,j;
    j=-1;
    nxt[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j]) j=nxt[j];
        nxt[++i]=++j;
    }
    if(m%(m-nxt[m])!=0)
        printf("1\n");
    else
        printf("%d\n",m/(m-nxt[m]));
}
int main()
{
    scanf("%s",x);
    while(x[0]!='.')
    {
        int len=strlen(x);
        kmp_pre(len);
        scanf("%s",x);
    }
    return 0;
}
