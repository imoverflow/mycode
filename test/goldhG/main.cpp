#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n==2&&m>=4||m==2&&n>=4||m-n>=2||n-m>=2)
            printf("YES\n");
        else{
            if((n+m-2)%2==1)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
