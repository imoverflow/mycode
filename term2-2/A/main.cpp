#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
            printf("no\n");
            continue;
        }
        int flag=0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n/=i;
                    flag=1;
                }
                break;
            }
        }
        if(n==1||flag==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
