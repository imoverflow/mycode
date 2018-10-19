#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,t,T;
        scanf("%d%d%d",&l,&t,&T);
        int sa=T%(2*l);
        if(sa>l)
            sa=2*l-sa;
        int sb=(T-t)%(2*l);
        if(T<=t)
            sb=0;
        sb+=l;
        sb%=(2*l);
        if(sb>l)
            sb=2*l-sb;
        printf("%d\n",abs(sa-sb));
    }
    return 0;
}
