#include <iostream>
#include <bits/stdc++.h>1
using namespace std;

char s[200005];
int helpme(char x)
{
    if(x=='L')
        return -1;
    else if(x=='R')
        return 1;
    else if(x=='U')
        return 2;
    else
        return -2;
}
int main()
{
    int n;
    cin>>n;
    cin>>s;
    int x=0,y=0;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int now=helpme(s[i]);
        if(now==2||now==-2)
        {
            if(y==0)
            {
                y=now;
                continue;
            }
            if(y*now<0)
            {
                ans++;
                y=now;
                x=0;
            }
        }else{
            if(x==0)
            {
                x=now;
                continue;
            }
            if(x*now<0)
            {
                ans++;
                x=now;
                y=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
