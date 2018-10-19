#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int s[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int t;
    cin>>t;
    int res=0;
    int ans=INF;
    for(int i=0;i<n;i++)
    {
        if(ans>t%s[i])
        {
            res=s[i];
            ans=t%s[i];
        }
    }
    printf("%d\n",res);
    return 0;
}
