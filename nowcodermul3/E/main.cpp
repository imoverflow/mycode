#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nxt[1000006];
void kmp_pre(char x[],int m)
{
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j]) j=nxt[j];
        nxt[++i]=++j;
    }
}
char s[1000005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    kmp_pre(s,len);
    int l=len-nxt[len];     //循环节的长度
    if(len%l==0&&l!=len)
    {
        printf("%d\n",l);
        for(int i=0;i<l;i++)
        {
            printf("%d",len/l);
            for(int j=i;j<len;j+=l)
            {
                printf(" %d",j);
            }
            printf("\n");
        }
    }else{
        printf("%d\n",len);
        for(int i=0;i<len;i++)
        {
            printf("1 %d\n",i);
        }
    }
    return 0;
}
