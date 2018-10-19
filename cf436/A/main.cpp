#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<int>s;
map<int,int>ma;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        s.insert(a);
        ma[a]++;
    }
    set<int>::iterator it=s.begin();
    if(s.size()==2&&ma[*it]==ma[*(++it)])
    {
        printf("YES\n");
        printf("%d %d",*s.begin(),*(++s.begin()));
    }else{
        printf("NO\n");
    }
    return 0;
}
