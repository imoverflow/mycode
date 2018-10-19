#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*************************************************/
/**             返回第一次匹配位置             **/
/*************************************************/
int fail[10];  //p=strlen(pat)
int kmp(char* str,char* pat)
{
    int i,j,k;
    memset(fail,-1,sizeof(fail));
    for(i=1;pat[i];i++)
    {
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]) fail[i]=k+1;
    }
    i=j=0;
    while(str[i]&&pat[j])
    {
        if(pat[j]==str[i])
        {
            i++,j++;
        }else if(j==0) i++;
        else j=fail[j-1]+1;
    }
    if(pat[j]) return -1;
    else return i-j;
}
/*************************************************/
/**                    END                      **/
/*************************************************/

/*----------------------------------------------------------------------------------------------------------------*/

/*************************************************/
/**             返回所有匹配位置               **/
/*************************************************/
int next[100];
void makeNext(const char P[],int next[])
{
    memset(next,0,sizeof next);
    int q,k;
    int m = strlen(P);
    next[0] = 0;
    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && P[q] != P[k])
            k = next[k-1];
        if (P[q] == P[k])
        {
            k++;
        }
        next[q] = k;
    }
}

int kmp(const char T[],const char P[],int next[])
{
    int n,m;
    int i,q;
    n = strlen(T);
    m = strlen(P);
    makeNext(P,next);
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && P[q] != T[i])
            q = next[q-1];
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m)
        {
            printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
    }
}
/*************************************************/
/**                    END                      **/
/*************************************************/
int main()
{
    char s1[]="bcdabefghiab";
    char s2[]="ab";
    printf("%d\n",kmp(s1,s2));
    kmp(s1,s2,next);
    return 0;
}
