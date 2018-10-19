#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        res=max(res,a+b);
    }
    cout<<res<<endl;
    return 0;
}
