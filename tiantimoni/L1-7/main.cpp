#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int h,w;
        scanf("%d%d",&h,&w);
        long long perfect=(h-100)*9*2*10;
        if(abs(100*w-perfect)<perfect/10)
        {
            printf("You are wan mei!\n");
        }else if(100*w-perfect>=perfect/10)
        {
            printf("You are tai pang le!\n");
        }else
        {
            printf("You are tai shou le!\n");
        }
    }
    return 0;
}
