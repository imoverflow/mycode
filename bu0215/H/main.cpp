#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int pre[100005];
int main()
{
    pre[0]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i%n]);
//        pre[i]=pre[i-1]+a[i];
    }
    int s,t;
    cin>>s>>t;
    int ans=0;
    for(int i=s;i<t;i++)
    {
        ans+=a[i%n];
    }
    int ans1=0;
    int res=-1;
    for(int i=0;i<n;i++)
    {
        int l=(s-i+n)%n;
        int r=(t-i+n)%n;
        ans-=a[r];
        ans+=a[l];
        if(ans>ans1)
        {
            ans1=ans;
            res=i;
        }
    }
    printf("%d\n",res+1);
    return 0;
}
