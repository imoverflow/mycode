#include <bits/stdc++.h>

using namespace std;
int s[100005];
int main(){
    int n,k,a;
    long long ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        while(s[i]>=k)
        {
            flag++;
            s[i]-=k;
        }
        if(s[i]>0)
        {
            flag++;
        }
        ans+=flag/2;
        flag%=2;
    }
    if(flag)
        ans++;
    printf("%I64d",ans);
    return 0;
}
