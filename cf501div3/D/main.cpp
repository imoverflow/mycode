#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,s;
    cin>>n>>k>>s;
    if((n-1)*k<s||k>s)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    long long x=(s-k)/(n-2);
    long long b=k-x;
    printf("YES\n");
    for(int i=0; i<x; i++)
    {
        if(i%2==0)
            printf("%d ",n);
        else
            printf("1 ");
    }
    long long res=s-x*(n-1);
    if(b==0)
        return 0;
    long long t=b;
    b--;
    bool flag;
    int p;
    if(x%2==1)
    {
        p=n;
        flag=false;
    }else{
        p=1;
        flag=true;
    }
    while(b--)
    {
        if(flag==true)
        {
            p++;
            printf("%d ",p);
            flag=false;
        }else{
            p--;
            printf("%d ",p);
            flag=true;
        }
    }
    res-=t-1;
    if(x%2==1)
        printf("%d",p-res);
    else
        printf("%d",p+res);
    return 0;
}
