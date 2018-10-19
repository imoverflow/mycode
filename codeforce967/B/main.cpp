#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
int s[100006];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    long long tot=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        tot+=s[i];
    }
    sort(s+1,s+n,cmp);
    s[n]=0;
    long long now=tot;
    for(int i=0;i<n;i++)
    {
        if(s[0]*a/now>=b)
        {
            cout<<i<<endl;
            return 0;
        }
        now-=s[i+1];
    }
    return 0;
}
