#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100005];
int t[100005];
int main()
{
    long long res1=0;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        if(t[i]==1)
            ans+=s[i];
        if(t[i]==0&&i<k)
            res1+=s[i];
    }
    long long ans1=ans;
    ans=max(ans,res1+ans);
    for(int i=1;i+k-1<n;i++)
    {
        ans=max(ans,ans1+res1+(t[i+k-1]==0)*s[i+k-1]-(t[i-1]==0)*s[i-1]);
        res1=res1+(t[i+k-1]==0)*s[i+k-1]-(t[i-1]==0)*s[i-1];
    }
    cout<<ans<<endl;
    return 0;
}
