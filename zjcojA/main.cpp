#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int k,n;
        scanf("%d%d",&k,&n);
        if(k%(1+n)==0)
            puts("Z");
        else
            puts("L");
    }
    return 0;
}
