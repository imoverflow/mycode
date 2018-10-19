#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[200005];
long long pre[200005];
int main()
{
    int n;
    cin>>n;
    long long res=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(i==0)
        {
            pre[i]=s[i];
        }else{
            pre[i]=pre[i-1]+s[i];
        }
        res+=s[i];
    }
    long long p=res/2+(res%2!=0);
    for(int i=0;i<n;i++)
    {
        if(pre[i]>=p)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
