#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int a,s1[6],s2[6];
int main()
{
    int n,ans=0;
    cin>>n;
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s1[a]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s2[a]++;
    }
    int flag=1;
    for(int i=1;i<=5;i++)
    {
        if((s1[i]+s2[i])%2==0)
        {
            ans+=abs(s1[i]-s2[i])/2;
        }else
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("%d\n",ans/2);
    else
        printf("-1\n");
    return 0;
}
