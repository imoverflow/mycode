#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int s[10];
char lim[20];
int main()
{
    priority_queue<vector<int>,vector<int>,less<int> >qq;
    while(!qq.empty())
    {
        qq.pop();
    }
    int sum=0;
    for(int i=0;i<7;i++)
    {
        scanf("%d",&s[i]);
        sum+=s[i];
        if(i!=0&&s[i]!=0)
            qq.push(i+1);
    }
    scanf("%s",lim);
    if(s[0]==0&&qq.empty())
    {
        printf("0\n");
        return 0;
    }else if(s[0]!=0&&qq.empty()){
        if(lim[0]=='R')
            printf("0\n");
        else if(lim[0]=='C')
            printf("1\n");
        else
            printf("1\n");
        return 0;
    }
    int ans=0;
    if(lim[0]=='C')
    {
//        ans++;
//        s[0]--;
        while(s[0]!=0)
        {
            ans+=qq.top();
            ans++;
            s[0]--;
        }
        while(!qq.empty())
        {
            ans+=qq.top();
            qq.pop();
        }
    }else if(lim[0]=='R')
    {
        ans+=qq.top();
        while(s[0]!=0)
        {
            ans+=1+qq.top();
            s[0]--;
        }
        while(!qq.empty())
        {
            ans+=qq.top();
            qq.pop();
        }
    }else if(lim[0]=='N'){
        if(s[0]==0)
        {
            while(!qq.empty())
            {
                ans+=qq.top();
                qq.pop();
            }
        }else{
            while(s[0]!=0)
            {
                ans+=qq.top();
//                qq.pop();
                ans++;
                s[0]--;
            }
            while(!qq.empty())
            {
                ans+=qq.top();
                qq.pop();
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
