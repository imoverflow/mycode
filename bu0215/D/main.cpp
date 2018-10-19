#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n>36)
        printf("-1\n");
    else{
        if(n==0)
            printf("0\n");
        else if(n==1)
            printf("4\n");
        else{
            int a=n/2;
            int b=n%2;
            for(int i=0;i<a;i++)
                printf("8");
            for(int i=0;i<b;i++)
                printf("0");
        }
    }
    return 0;
}
