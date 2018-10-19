#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[200005];
vector<int> g[200005];
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    int p=0;
    int cnt=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='0')
        {
            g[++p].push_back(i);
        }else{
            if(p==0)
            {
                printf("-1\n");
                return 0;
            }else{
                g[p--].push_back(i);
            }
        }
        cnt=max(cnt,p);
    }
    if(p!=cnt) return printf("-1\n"),0;
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d",g[i].size());
        for(int j=0;j<g[i].size();j++)
        {
            printf(" %d",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
