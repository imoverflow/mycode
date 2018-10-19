#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char,int>ma;
char s[3][1000006];
int main()
{
    int n;
    cin>>n;
    int ans[3]={0};
    for(int i=0;i<3;i++)
    {
        scanf("%s",s[i]);
        int len=strlen(s[i]);
        for(int j=0;j<len;j++)
        {
            ma[s[i][j]]++;
        }
        for(map<char,int>::iterator it=ma.begin();it!=ma.end();it++)
        {
            ans[i]=max(ans[i],it->second);
        }
        if(ans[i]+n<=len)
        {
            ans[i]=ans[i]+n;
        }else{
            if(n==1)
                ans[i]=len-1;
            else
                ans[i]=len;
        }
        ma.clear();
    }
    if(ans[0]>ans[1]&&ans[0]>ans[2])
    {
        cout<<"Kuro"<<endl;
    }else if(ans[1]>ans[0]&&ans[1]>ans[2])
    {
        cout<<"Shiro"<<endl;
    }else if(ans[2]>ans[0]&&ans[2]>ans[1])
    {
        cout<<"Katie"<<endl;
    }else
    {
        cout<<"Draw"<<endl;
    }
    return 0;
}










