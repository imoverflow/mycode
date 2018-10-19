#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef unsigned long long ull;
const ull B=mod;
//void kmp_pre(char x[],int m,long long next[])        //两种处理方法
//{
//    int i,j;
//    j=next[0]=-1;
//    i=0;
//    while(i<m)
//    {
//        while(-1!=j&&x[i]!=x[j]) j=next[j];
//        next[++i]=++j;
//    }
//}
////void preKMP(char x[],int m,int kmpNext[])
////{
////    int i,j;
////    j=kmpNext[0]=-1;
////    i=0;
////    while(i<m)
////    {
////        while(-1!=j&&x[i]!=x[j]) j=kmpNext[j];
////        if(x[++i]==x[++j]) kmpNext[i]=kmpNext[j];
////        else kmpNext[i]=j;
////    }
////}
//long long next[10010];
//long long kmp_count(char x[],int m,char y[],int n)
//{
//    long long i,j;
//    long long ans=0;
//    kmp_pre(x,m,next);
//    i=j=0;
//    while(i<n)
//    {
////        while(-1!=j&&y[i]!=x[j])
////        {
////            j=next[j];
////        }
//        while(y[i]!=x[j])
//        {
//            if(j==-1) break;
//            ans+=(j+2)*(j+1)/2;
//            j=next[j];
//        }
////        if(j!=-1&&j<m-1)
////        {
////            ans=(ans+j*(j+1)/2)%mod;
////        }
////        else{
////            ans=(ans+j*(j+1)/2)%mod;
////        }
//        i++;
//        j++;
//        if(j>=m)
//        {
//            ans=(ans+m)%mod;
//            j=next[j];
//        }
//    }
//    return ans;
//}
long long contain(string a,string b)
{
    long long ans=0;
    int a1=a.length(),b1=b.length();
//    if(a1>b1) return false;
    ull t=1;
    for(int i=0;i<a1;i++) t*=B;
    ull ah=0,bh=0;
    for(int i=0;i<a1;i++)
        ah=ah*B+a[i];
    for(int i=0;i<a1;i++)
        bh=bh*B+b[i];
    for(int i=0;i+a1<=b1;i++)
    {
        if(ah==bh) ans+=i;
        if(i+a1<b1) bh=bh*B+b[i+a1]-b[i]*t;
    }
    return ans;
}
//long long overlap(string a,string b)
//{
//    int al=a.length(),bl=b.length();
//    long long ans=0;
//    ull ah=0,bh=0,t=1;
//    for(int i=1;i<=min(al,bl);i++)
//    {
//        ah=ah+a[al-i]*t;
//        bh=bh*B+b[i-1];
//        if(ah==bh) ans+=i;
//        t*=B;
//    }
//    return ans;
//}
char T[1000006];
char P[1000006];

int main()
{
    freopen("a.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",T);
        scanf("%s",P);
        int len1=strlen(T);
        int len2=strlen(P);
//        for(int i=len1;i<len1+len2;i++)
//        {
//            T[i]='0';
//        }
//        T[len1+len2]=0;
//        for(int i=0;i<len2/2;i++)
//        {
//            swap(P[i],P[len2-i-1]);
//        }
//        for(int i=0;i<(len1+len2)/2;i++)
//        {
//            swap(T[i],T[len1+len2-i-1]);
//        }
//        long long k=kmp_count(P,len2,T,len1+len2);
        printf("%lld\n",contain(T,P));
    }
    return 0;
}
