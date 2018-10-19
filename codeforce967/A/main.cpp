#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;

int ss[200];
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        ss[i]=a*60+b;
    }
    sort(ss+1,ss+n+1);
    ss[n+1]=INF;
    ss[0]=-INF;
    if(s<ss[1])
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(ss[i+1]>2*s+ss[i]+1)
        {
            cout<<(ss[i]+s+1)/60<<" "<<(ss[i]+s+1)%60<<endl;
            return 0;
        }
    }
    return 0;
}
