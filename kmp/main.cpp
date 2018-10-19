#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void kmp_pre(char x[],int m,int next[])        //两种处理方法
{
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j]) j=next[j];
        next[++i]=++j;
    }
}
void preKMP(char x[],int m,int kmpNext[])
{
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j]) j=kmpNext[j];
        if(x[++i]==x[++j]) kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}
int next[10010];
int kmp_count(char x[],int m,char y[],int n)
{
    int i,j;
    int ans=0;
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j&&y[i]!=x[j])
            j=next[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main()
{
    char T[] = "ababxbababcadfdsss";
    char P[] = "ab";
    printf("%s\n",T);
    printf("%s\n",P );
    int len1=strlen(T);
    int len2=strlen(P);
    int k=kmp_count(P,len2,T,len1);
    for (int i = 0; i < strlen(P); ++i)
    {
        printf("%d ",next[i]);
    }
    printf("\n num is%d\n",k);
    printf("\n");
    return 0;
}
