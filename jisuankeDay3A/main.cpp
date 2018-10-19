#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,t,L;
    cin>>L>>t>>T;
    int b=0;
    int po1=0,po2=L;
    if(T/L%2==0)
    {
        po1=T%L;
    }else{
        po1=L-T%L;
    }
    if(t>=T)
    {
        po2=L;
    }else{
        if((T-t)/L%2==0){
            po2=L-(T-t)%L;
        }else{
            po2=(T-t)%L;
        }
    }
    printf("%d",abs(po2-po1));
    return 0;
}
