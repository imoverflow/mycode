#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p;

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
int next[1000010];
int kmp_count(char x[],int m,char y[],int n)
{
    int i,j;
    int ans=0;
    makeNext(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j&&y[i]!=x[j])
            j=next[j];
        i+=p;
        j+=p;
        if(j>=m)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
char s1[1000006];
char s2[1000006];
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n,m;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s1[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&s2[i]);
        }
        int k=kmp_count(s1,n,s2,m);
        printf("Case #%d: %d\n",cas++,k);
    }
    return 0;
}
