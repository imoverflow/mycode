#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==0)
            ans+=32;
        else if(a==1)
            ans+=16;
        else if(a==2)
            ans+=8;
        else if(a==4)
            ans+=4;
        else if(a==8)
            ans+=2;
        else if(a==16)
            ans+=1;
    }
    printf("%.10f\n",1.0*ans/16);
    return 0;
}
