#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int cases=1;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        regex reg(t);
        printf("Case %d: ",cases++);
        printf("%s\n",regex_match(s,reg)?"Yes":"No");
    }
    return 0;
}
