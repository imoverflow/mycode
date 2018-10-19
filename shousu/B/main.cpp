#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s1[1005];
char s2[1005];
bool vis[500];
map<char,char>ma;
int main()
{
    cin>>s1>>s2;
    int cnt=0;
    int len=strlen(s1);
    for(int i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
        {
            if(ma[s1[i]]==0&&ma[s2[i]]==0)
            {
                cnt++;
                ma[s1[i]]=s2[i];
                ma[s2[i]]=s1[i];
            }else if(ma[s1[i]]==s2[i]&&ma[s2[i]]==s1[i])
                continue;
            else{
                printf("-1\n");
                return 0;
            }
        }else{
            if(ma[s1[i]]==0||ma[s1[i]]==s1[i])
                ma[s1[i]]=s1[i];
            else {
                printf("-1\n");
                return 0;
            }
        }
    }
    if(cnt==0)
        cout<<0<<endl;
    else if(cnt==-1)
        cout<<-1<<endl;
    else{
        cout<<cnt<<endl;
        for(char i='a';i<='z';i++)
        {
            if(!vis[i]&&ma[i]!=i&&ma[i]!=0)
            {
                printf("%c %c\n",i,ma[i]);
                vis[i]=1;
                vis[ma[i]]=1;
            }
        }
    }
    return 0;
}
