#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,s[100005];
    scanf("%d",&t);
    while(t--)
    {
        int sum=0,ans=0;
        int n,v;
        scanf("%d%d",&n,&v);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        for(int i=0;i<n;i++)
        {
            if(sum+s[i]<=v)
            {
                ans++;
                sum+=s[i];
            }else
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
