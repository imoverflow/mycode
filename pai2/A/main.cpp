#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        long long v;
        long long ans;
        if(l%2==1&&r%2==1)
        {
            v=(r-l)/2+1;
            ans=v*l+v*(v-1);
        }
        else if(l%2==1)
        {
            v=(r-l)/2+1;
            ans=v*l+v*(v-1);
        }else if(r%2==1){
            v=(r-l)/2+1;
            ans=v*(l+1)+v*(v-1);
        }else{
            v=(r-l)/2;
            ans=v*(l+1)+v*(v-1);
        }
        printf("Case %d: ",cas++);
        printf("%lld\n",ans);
    }
    return 0;
}
