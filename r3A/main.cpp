#include <iostream>
#include <stdio.h>
using namespace std;
int absa(int n)
{
    if(n<0)
        return -1*n;
    else
        return n;
}
int main()
{
    int n,ans=0;
    char b,s[205];
    scanf("%d",&n);
    getchar();
    pair<int,int > p;
    p.first=0,p.second=0;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&s[i]);
        if(s[i]=='U')
            p.second++;
        if(s[i]=='D')
            p.second--;
        if(s[i]=='L')
            p.first--;
        if(s[i]=='R')
            p.first++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int x=p.first,y=p.second;
            for(int k=i;k<=j;k++)
            {
                if(s[k]=='U')
                    y+=1;
                if(s[k]=='D')
                    y-=1;
                if(s[k]=='L')
                    x-=1;
                if(s[k]=='R')
                    x+=1;
            }
            if(x==p.first&&y==p.second)
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
