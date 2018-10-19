#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<string,int> >g;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        int p;
        cin>>s>>p;
        g.push_back(make_pair(s,p));
    }
    int ans=0;
    for(int i=0;i<g.size();i++)
    {
        string s;
        int va;
        tie(s,va)=g[i];
        t=s;
        reverse(s.begin(),s.end());
        if()
    }
    return 0;
}
