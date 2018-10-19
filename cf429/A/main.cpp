#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[11000];
int x[100];
set<char>ss;
int main()
{
    int n,k;
    memset(s,0,sizeof s);
    memset(x,0,sizeof x);
    ss.clear();
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        x[s[i]-'a']++;
        ss.insert(s[i]);
    }
    int flag=1;
    for(int i=0;i<26;i++)
    {
        if(x[i]>k&&x[i]!=0)
        {
            flag=0;
            break;
        }
    }
    if(flag&&n>=k)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
