#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long s[1000006];
int q,k;
void init(){
    s[0]=1;
    for(int i=1;i<=1000000;i++){
        if(i>=k) s[i]=s[i-1]+s[i-k];
        else s[i]=1;
    }
}
int main()
{
    cin>>q>>k;
    init();
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%lld\n",s[r-l+1]);
    }
    return 0;
}
