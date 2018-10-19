#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    long long ans=0;
    for(int i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        if(b<0){
            if(n%2==1)
            {
                long long n1=n/2+1;
                ans+=2*(n1*a+n1*(n1-1)/2*b)-a;
            }else{
                long long n1=n/2+1;
                ans+=2*(n1*a+n1*(n1-1)/2*b)-a-(a+b*(n1-1));
            }
        }else{
            ans+=n*a+n*(n-1)/2*b;
        }
//        cout<<ans<<endl;
    }
    printf("%.10f\n",ans/(1.0*n));
    return 0;
}
