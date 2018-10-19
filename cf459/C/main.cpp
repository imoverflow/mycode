#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[5005];
int len;
char t[5005];
int dp[5005][5005];
bool check(int l,int r)
{
    if((r-l)%2!=1)
        return false;

    stack<char>ss;
    for(int i=l;i<=r;i++)
    {
        if(ss.empty())
        {
            ss.push(s[i]);
        }else{
            if(s[i]==')')
            {
                if(!ss.empty())
                {
                    if(ss.top()=='(')
                    {
                        ss.pop();
                    }else{
                        ss.push(s[i]);
                    }
                }
            }else{
                ss.push(s[i]);
            }
        }
    }
    if(ss.empty())
        return true;
    else
    {
        if(ss.top()==')'||ss.top()=='(')
            return false;
        while(!ss.empty())
        {
//            char v=ss.top();
            ss.pop();
            if(ss.empty())
                break;
            char v=ss.top();
            if(v=='('||v=='?')
            {
                ss.pop();
            }
        }
        if(ss.empty())
            return true;
        else
            return false;
    }
}
//bool check(int l,int r)
//{
//    if(s[l]==')'||s[r]=='(')
//        return false;
//    for(int i=l,j=r;i<=j;i++,j--)
//    {
//        if(s[i]=='('&&s[j]=='('||s[i]==')'&&s[j]==')')
//        {
//            return false;
//        }
//    }
//    return true;
//}
int main()
{
    scanf("%s",s);
    len=strlen(s);
    long long ans=0;
    int l=0,r=1;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j+=2)
        {
            if(check(i,j))
            {
                printf("%d %d\n",i,j);
                ans++;
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
