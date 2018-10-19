#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,j=n/2+1,k=1;k<=n;i++,j++,k+=2)
    {
        ans[k]=i;
        ans[k+1]=j;
    }
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }else{
        ans[n]=n;
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
