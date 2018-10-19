#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[200];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>=8) ans+=8;
        else ans+=s[i];
        if(ans>=k){
            printf("%d\n",i+1);
            exit(0);
        }
    }
    printf("-1\n");
    return 0;
}
