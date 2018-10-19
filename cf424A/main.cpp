#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int s[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int flag1=0,flag2=0,flag=1,flag3=0;
    if(n==1)
    {
        puts("YES");
        return 0;
    }
    int sam=0;
    for(int i=0;i<n-1;i++)
    {
        if(i+1<n)
        {
            if(s[i]<s[i+1]&&flag1==0&&flag3==0)
                flag1=1;
            else if(s[i]>s[i+1]&&flag2==0&&flag3==0)
            {
                flag2=1;
                flag1=0;
            }
            else if(s[i]==s[i+1]&&flag3==0)
            {
                if(flag2==1)
                    flag=0;
                flag2=0;
                flag1=0;
                flag3=1;
                sam=s[i];
            }
            if(flag1){
                if(s[i]>s[i+1])
                    flag=0;
            }
            if(flag2)
            {
                if(s[i]<s[i+1])
                    flag=0;
            }
            if(flag3)
            {
                if(s[i]<s[i+1]||s[i+1]==s[i]&&s[i+1]!=sam&&s[i]!=sam)
                    flag=0;
            }
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
