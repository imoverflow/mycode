#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[100];
bool check(int l,int r)
{
    for(int i=l,j=r;i<=j;i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int p=strlen(s);
        int ans=1;
        for(int i=0;i<p;i++)
        {
            for(int j=i+1;j<p;j++)
            {
                if(check(i,j))
                    ans=max(ans,j-i+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
