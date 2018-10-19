#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long long>g;
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            g.push_back(i);
            g.push_back(n/i);
        }
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<g.size();i++)
    {
        double s=1.0*g[i]*k*(k-1)/2;
        if(n-s>(k-1)*g[i])
        {
            for(int j=1;j<k;j++)
            {
                cout<<j*g[i]<<" ";
            }
            cout<<(long long)(n-s)<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
