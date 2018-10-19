#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[500];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n*2;i++)
    {
        scanf("%d",&s[i]);
    }
    sort(s,s+n*2);
    if(s[n]>s[n-1])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
