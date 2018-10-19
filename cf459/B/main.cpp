#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<string,string>ma;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        ma[b]=a;
    }
    for(int i=0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        b.erase(--b.end());
        cout<<a<<" "<<b<<";"<<" #"<<ma[b]<<endl;
    }
    return 0;
}
