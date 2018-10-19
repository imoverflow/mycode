#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[200005];
char t[200005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    scanf("%s",t);
    int is=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            is=i;
            break;
        }
    }
    if(is==-1)
    {
        if(strcmp(s,t)==0)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        return 0;
    }
    bool flag=true;
    for(int i=0;i<is;i++)
    {
        if(s[i]!=t[i])
        {
            flag=false;
            break;
        }
    }
    for(int i=n-1,j=m-1;i>is;i--,j--)
    {
        if(s[i]!=t[j]||j<is)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
