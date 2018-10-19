#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int st,cnt,p;
}s[3];
int main()
{
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    int a,b,c;
    memset(s,0,sizeof s);
    s[0].st=1;
    s[0].p=p;
    s[1].st=2;
    s[1].p=q;
    s[2].st=3;
    s[2].p=r;
    for(int i=0;i<100;i++)
    {
        int ma;
        for(int j=0;j<3;j++)
        {
            if(s[0].cnt==s[1].cnt&&s[0].cnt==s[2].cnt)
            {
                int p=max(s[0].p,max(s[1].p,s[2].p));
                if(p==s[0].p)
                {
                    ma=0;
                }else if(p==s[1].p)
                {
                    ma=1;
                }else{
                    ma=2;
                }
            }else if(s[0].cnt==s[1].cnt&&s[0].cnt>s[2].cnt)
            {
                if(s[2].p>s[0].p)
                {
                    ma=2;
                }else{
                    ma=0;
                }
            }else if(s[0].cnt==s[1].cnt&&s[0].cnt<s[2].cnt)
            {
                ma=1;
            }else if(s[0].cnt==s[2].cnt&&s[0].cnt>s[1].cnt)
            {
                if(s[2].p>s[1].p)
                {
                    ma=2;
                }else{
                    ma=1;
                }
            }else if(s[0].cnt==s[2].cnt&&s[0].cnt<s[1].cnt)
            {
                ma=0;
            }else if(s[1].cnt==s[2].cnt&&s[1].cnt>s[0].cnt)
            {
                if(s[0].p>s[1].p)
                {
                    ma=0;
                }else{
                    ma=1;
                }
            }else if(s[1].cnt==s[2].cnt&&s[1].cnt<s[0].cnt)
            {
                ma=2;
            }else{
                int p=max(s[0].cnt,max(s[1].cnt,s[2].cnt));
                if(p==s[0].cnt)
                {
                    ma=2;
                }else if(p==s[1].cnt)
                {
                    ma=0;
                }else{
                    ma=1;
                }
            }
        }
        if(ma==0)
        {
            printf("3\n");
            s[2].cnt++;
        }else if(ma==1)
        {
            printf("1\n");
            s[0].cnt++;
        }else{
            printf("2\n");
            s[1].cnt++;
        }
    }
    return 0;
}
