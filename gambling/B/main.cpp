#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        if(a==0&&b==0) break;
        int flag=0;
        while(1)
        {
            if(a>b) swap(a,b);
            if(b%a==0) break;
            if(b<a*2) b-=a;
            if(b>a*2) break;
            flag++;
        }
        if(flag%2==0) puts("Stan wins");
        else puts("Ollie wins");
    }
    return 0;
}
