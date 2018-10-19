#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Create(long long res[],int n,unsigned int A, unsigned int B, unsigned int c){

    for(int i=0;i<n;i++){
        res[i]=A+B;
        A=((A<<2)+c)*i*29+B;
        B=(((A+B)<<3)+c)*17;
    }
}
int n;
unsigned int a,b,c;
long long k;
long long res[1000006];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>a>>b>>c>>k;
        Create(res,n,a,b,c);
        nth_element(res,res+n-k,res+n);
        cout<<res[n-k]<<endl;
    }
    return 0;
}
