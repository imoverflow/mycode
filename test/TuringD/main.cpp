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
            printf(" /\\\n");
            printf("/__\\\n");
        }
        if(n==2)
        {
            printf("   /\\\n");
            printf("  /__\\\n");
            printf(" /\\/\\\n");
            printf("/__\\/__\\\n");
        }
    }
    return 0;
}
