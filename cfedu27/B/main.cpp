#include <iostream>
#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,less<int> >q;
char s[100];
int main()
{
    int sum1=0,sum2=0;
    scanf("%s",s);
    for(int i=0;i<3;i++)
    {
        sum1+=s[i]-'0';
    }
    for(int i=3;i<6;i++)
    {
        sum2+=s[i]-'0';
    }
    if(sum1==sum2)
    {
        printf("0\n");
    }else if(sum1<sum2)
    {
        for(int i=0;i<3;i++)
        {
            q.push(9-(s[i]-'0'));
        }
        for(int i=3;i<6;i++)
        {
            q.push(s[i]-'0');
        }
        int p=0,cnt=0;
        while(sum1+p<sum2)
        {
            cnt++;
            p+=q.top();
            q.pop();
        }
        printf("%d\n",cnt);
    }else{
        for(int i=3;i<6;i++)
        {
            q.push(9-(s[i]-'0'));
        }
        for(int i=0;i<3;i++)
        {
            q.push(s[i]-'0');
        }
        int p=0,cnt=0;
        while(sum2+p<sum1)
        {
            cnt++;
            p+=q.top();
            q.pop();
        }
        printf("%d\n",cnt);
    }
    return 0;
}
