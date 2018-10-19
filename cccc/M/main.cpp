#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

char s[1005][1005];
int main()
{
    int n,m;
    int ans=0,res=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                {
                    res++;
                }else if(s[i][j]=='L')
                {
                    ans=max(ans,res);
                    res=0;
                }
            }
        }else{
            for(int j=m-1;j>=0;j--)
            {
                if(s[i][j]=='.')
                {
                    res++;
                }else if(s[i][j]=='L')
                {
                    ans=max(ans,res);
                    res=0;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
