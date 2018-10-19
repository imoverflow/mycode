#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char t[10000];
char s[10000];
int nxt[10000];
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
int kmp_count(char x[],int m,char y[],int n,int l,int r)
{
    int i,j;
    int ans=0;
//    kmp_pre(x,m);
    j=0;
    i=l;
    while(i<=r)
    {
        while(-1!=j&&y[i]!=x[j])
            j=nxt[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    scanf("%s",s);
    scanf("%s",t);
    kmp_pre(t,m);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        printf("%d\n",kmp_count(t,m,s,n,l,r));
    }
    return 0;
}
