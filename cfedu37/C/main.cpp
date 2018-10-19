#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> s;
char key[200005];
bool vis[200005];
int main()
{
    int n;
    scanf("%d",&n);
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        s.push_back(a);
    }
    scanf("%s",key);
    int len=strlen(key);
    int pre=0;
    for(int i=0;i<len;i++)
    {
        if(key[i]=='0')
        {
            for(int j=pre;j<=i;j++)
            {
                if(s[j]>i+1)
                {
                    printf("NO\n");
                    return 0;
                }
            }
            pre=i+1;
        }
    }
    printf("YES\n");
    return 0;
}
