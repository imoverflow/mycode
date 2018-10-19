#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[1550];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
                cnt++;
        }
    }
    scanf("%d",&m);
    cnt%=2;
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int x=r-l+1;
        if(x*(x-1)/2%2==1) cnt^=1;
        if(cnt) printf("odd\n");
        else printf("even\n");
    }
    return 0;
}
