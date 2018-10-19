#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[100005];
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i]);
        sum+=s[i];
    }
    if(sum%2!=0)
    {
        puts("No");
        return 0;
    }
    sort(s,s+n);
    long long sum1=0,sum2=0;
    for(int i=0;i<n/2;i++)
    {
        sum1+=s[i];
        sum2+=s[n-1-i];
        if(i+1<=(n/2+(n%2==1))){
            sum1+=s[n-2-i];
            sum2+=s[i+1];
        }
    }
    if(n%2==0)
    {
        if(sum1==sum2)
            puts("Yes");
        else
            puts("No");
    }else{
        if(sum1<sum2)
            sum1+=s[n/2];
        else
            sum2+=s[n/2];
        if(sum1==sum2)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
