#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a=k/(m*2)+(k%(m*2)!=0);
    int b=(k-k/(m*2)*(2*m))/2+((k-k/(m*2)*(2*m))%2!=0);
    if(b==0)
        b=m;
    if(k%2==1)
    {
        cout<<a<<" "<<b<<" "<<"L"<<endl;
    }else{
        cout<<a<<" "<<b<<" "<<"R"<<endl;
    }
    return 0;
}
