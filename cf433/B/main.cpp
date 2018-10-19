#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==0)
    {
        printf("0 0");
        return 0;
    }
    if(n>k)
    {
        printf("1 ");
    }else{
        printf("0 ");
    }
    if(n==k)
    {
        printf("0");
        return 0;
    }
    if(k==n/2)
    {
        printf("%d",n/2+(n%2==1));
    }else if(k<n/2)  //
    {
        printf("%d",min(n/3,k)*2+(n%3>1&&k>n/3));
    }else if(k>n/2)
    {
        printf("%d",n-k);
    }
    return 0;
}
