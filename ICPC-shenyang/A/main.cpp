#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    srand(time(0));
    while(t--)
    {
        int x=rand();
        if(x%2==0)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
