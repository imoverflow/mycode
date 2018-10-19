#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[1000006];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            ans^=s[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>(ans^s[i]))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
