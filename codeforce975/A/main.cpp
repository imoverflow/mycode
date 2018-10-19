#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[1003][1003];
set<char>x;
set<string>cnt;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++)
    {
        x.clear();
        int len=strlen(s[i]);
        for(int j=0;j<len;j++)
        {
            x.insert(s[i][j]);
        }
        string m="";
        for(auto j:x)
        {
            m=m+j;
        }
        cnt.insert(m);
    }
    cout<<cnt.size()<<endl;
    return 0;
}
