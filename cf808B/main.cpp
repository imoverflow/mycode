#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[1000005];
int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    double sum;
    double ans=0;
    for(int i=1;i<=n;)
    {
        sum=0;
        while(i++%k!=0)
        {
            sum+=s[i-1];
        }
        ans+=sum/k;
    }
    printf("%.10f",ans);
    return 0;
}
