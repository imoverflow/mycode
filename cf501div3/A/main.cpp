#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            s[i]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(s[i]==0)
            cnt++;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=m;i++)
    {
        if(s[i]==0)
        {
            printf("%d ",i);
        }

    }
    cout<<endl;
    return 0;
}
