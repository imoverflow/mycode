#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[1000005];
void init(){
    memset(s,0,sizeof s);
    for(int i=1;i<100001;i++){
        for(int j=i;j<100001;j+=i){
            s[j]++;
        }
    }
}
long long get(int a){
    return s[a];
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        long long ans=1;
        ans*=get(a);
        ans*=get(b);
        ans*=get(c);
        cout<<ans<<endl;
    }
    return 0;
}
