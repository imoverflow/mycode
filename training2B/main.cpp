#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f;
bool check(int m,int n,int o,int p)
{
    int z=max(m,o),q=n+p;
    if(z<=a&&q<=b||z<=b&&q<=a)
        return true;
    else
        return false;
}
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    if(check(c,d,e,f)||check(c,d,f,e)||check(d,c,e,f)||check(d,c,f,e))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
