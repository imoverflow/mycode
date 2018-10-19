#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<string,int>ma;
int main()
{
    int n;
    cin>>n;
    ma.clear();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ma[s]++;
    }
    if(ma["red"]==0)
    {
        map<string,int>::iterator it=ma.begin();
        int ans=0;
        while(it!=ma.end())
        {
            string s=(*it).first;
            if(s=="black")
                ans+=7;
            else if(s=="pink")
                ans+=6;
            else if(s=="blue")
                ans+=5;
            else if(s=="brown")
                ans+=4;
            else if(s=="green")
                ans+=3;
            else if(s=="yellow")
                ans+=2;
            it++;
        }
        printf("%d\n",ans);
        return 0;
    }else if(ma["red"]!=0&&(ma["black"]!=0||ma["pink"]!=0||ma["blue"]!=0||ma["green"]!=0||ma["brown"]!=0||ma["yellow"]!=0)){
        int ans=0;
        if(ma["black"]!=0)
        {
            ans+=8*ma["red"];
        }else if(ma["pink"]!=0)
        {
            ans+=7*ma["red"];
        }else if(ma["blue"]!=0)
        {
            ans+=6*ma["red"];
        }else if(ma["brown"]!=0)
        {
            ans+=5*ma["red"];
        }else if(ma["green"])
        {
            ans+=4*ma["red"];
        }else if(ma["yellow"]){
            ans+=3*ma["red"];
        }
        map<string,int>::iterator it=ma.begin();
        while(it!=ma.end())
        {
            string s=(*it).first;
            if((*it).second==0)
            {
                it++;
                continue;
            }
            if(s=="black")
                ans+=7;
            else if(s=="pink")
                ans+=6;
            else if(s=="blue")
                ans+=5;
            else if(s=="brown")
                ans+=4;
            else if(s=="green")
                ans+=3;
            else if(s=="yellow")
                ans+=2;
            it++;
        }
        printf("%d\n",ans);
        return 0;
    }else{
        printf("1\n");
        return 0;
    }
    return 0;
}
