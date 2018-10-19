#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
set<long long>ss;
void init()
{
    for(long long i=1;i*i<=2e9;i++)
    {
        ss.insert(i*i);
    }
}
int main()
{
    init();
    char s[10];
    scanf("%s",s);
    int len=strlen(s);
    long long ans=INF;
    for(int i=0;i<(1<<len);i++)
    {
        int p=i;
        long long res=0;
        int cnt=0;
        int cnt1=0;
        bool flag=true;
        for(int j=0;j<len;j++)
        {
            if(p&(1<<j))
            {
                if(flag)
                {
                    cnt=s[j]-'0';
                    flag=false;
                }
                res=res*10+s[j]-'0';
                cnt1++;
            }
        }
        if(cnt==0)
            continue;
        if(ss.find(res)!=ss.end())
        {
            ans=min(ans,(long long)len-cnt1);
        }
    }
    if(ans!=INF)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
