#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int h,r,t;
}s[200];
int main()
{
    int n;
    cin>>n;
    int ma=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].h>>s[i].r>>s[i].t;
        ma=max(ma,s[i].h);
    }
    for(int i=0;i<=ma*1825;i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(s[j].r<s[j].t)
            {
                int now=i%s[j].h;
                if(now>s[j].r&&now<s[j].t)
                {
                    flag=false;
                    break;
                }
            }else{
                int now=i%s[j].h;
                if(now<s[j].t||now>s[j].r)
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}
