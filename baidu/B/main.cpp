#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        scanf("%d",&p);
        if(p%10!=0)
        {
            printf("1\n");
        }else{
            printf("3\n");
        }
    }
    return 0;
}
