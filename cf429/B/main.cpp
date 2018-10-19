#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[1000006];
long long pre[1000006];
int main()
{
    memset(s,0,sizeof s);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        if(i!=0)
            pre[i]=pre[i-1]+s[i];
        else
            pre[i]=s[i];
    }
    int flag=0;
    for(int i=n-1;i>=0;i--)
    {
        if(pre[i]%2==1&&(pre[n-1]-pre[i])%2==1)
        {
            flag=1;
            break;
        }
    }
    if(pre[n-1]%2==1)
        flag=1;
    if(flag)
    {
        printf("First\n");
    }else{
        printf("Second\n");
    }
    return 0;
}
