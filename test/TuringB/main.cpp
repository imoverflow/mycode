#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[20];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<10;i++)
            scanf("%d",&s[i]);
        sort(s,s+10);
        printf("%d %d\n",n,s[7]);
    }

    return 0;
}
