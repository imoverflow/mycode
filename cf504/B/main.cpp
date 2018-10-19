#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    if(n>=k)
    {
        if(k%2==1)
        {
            cout<<k/2<<endl;
        }else{
            cout<<(k-1)/2<<endl;
        }
//        return 0;
    }else{
        long long res=n-k/2;
        cout<<max(0ll,res)<<endl;
    }
    return 0;
}
