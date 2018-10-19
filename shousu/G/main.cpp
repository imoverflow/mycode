#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[20];
int n;
int v[20];
void add(int x)
{
    for(int i=0;i<n;i++)
    {
        v[i]+=x;
    }
}
bool check()
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=0||v[i]>=10&&v[i]!=11)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        v[i]=s[i]-'0';
        if(v[i]==0)
            v[i]=11;
    }

    add(-3);
    if(check())
    {
        printf("NO\n");
        return 0;
    }
    add(3);
    add(3);
    if(check())
    {
        printf("NO\n");
        return 0;
    }
    add(-3);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1||v[i]==4||v[i]==7||v[i]==11)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("NO\n");
        return 0;
    }
    flag=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==3||v[i]==6||v[i]==9||v[i]==11)
        {
            flag=1;
        }
    }
    if(flag==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
