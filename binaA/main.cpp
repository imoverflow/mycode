#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int s[1000005]={0};
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        map<int,int> cnt;
        set<int> all;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            all.insert(s[i]);
        }
        int num=all.size();
        int x=0,y=0,ans=n,t=0;
        while(1)
        {
            while(t<num&&y<n)
            {
                if(cnt[s[y]]++==0)
                    t++;
                y++;
            }
            if(t<num) break;
            ans=min(ans,y-x);
            if(cnt[s[x]]--==1)
            {
                t--;
            }
            x++;
        }
        printf("%d\n",ans);
    }

    return 0;
}
