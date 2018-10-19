#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[100005];
char q[100005];
char good[30]={0};
bool solve(char *a,char *b)
{
    int len1=strlen(a);
    int len2=strlen(b);
    if(len1+1<len2) return false;
    int l=0,r=len2-1,x=len1-1;
    int ul=0,ur=len1-1,dl=0,dr=len2-1;
    while(b[l]!='*'&&l<len2)
    {
        if(b[l]!='?')
        {
            if(b[l]!=a[l])
                return false;
        }else{
            if(good[a[l]-'a']!=1)
                return false;
        }
        l++;
        ul++;
        dl++;
    }
    while(b[r]!='*'&&r>=0)
    {
        if(b[r]!='?')
        {
            if(b[r]!=a[x])
                return false;
        }else{
            if(good[a[x]-'a']!=1)
                return false;
        }
        r--;
        x--;
        ur--;
        dr--;
    }
    if(len1>=len2)
    {
        for(int i=l;i<=r;i++)
        {
            if(good[a[i]-'a']!=0)
                return false;
        }
    }
    for(int i=dr;i<=ur;i++)
    {
        if(good[a[i]-'a']!=0)
            return false;
    }
    return true;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    char t;
    while(scanf("%c",&t))
    {
        if(t<'a'||t>'z')
            break;
        good[t-'a']=1;
    }
    scanf("%s",s);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",q);
        if(solve(q,s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
b
aa*
10
aaab

b
aa*aa
10
aaa
cba
?*cbc
88
ccbc
*/
