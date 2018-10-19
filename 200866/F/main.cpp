#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans[100005];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
//        for(int i=0,j=1;i<n,j<=n;i+=2,j++)
//        {
//            ans[i]=j;
//        }
//        for(int i=1,j=n/2+1+(n%2==1);i<n,j<=n;i+=2,j++)
//        {
//            ans[i]=j;
//        }
////        ans[n-2]=n-1;
        for(int i=1,j=n/2+1+(n%2==1),k=1;k<=n;k++)
        {
            if(k%2==1)
            {
                printf("%d ",i);
                i++;
            }
            else
            {
                printf("%d ",j);
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}
