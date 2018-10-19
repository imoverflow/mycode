#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define pi 3.1415926535898
using namespace std;
int s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof(s));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        int flag=1;
        int ad=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if((s[j]-s[i])%2!=0)
            {
                flag=0;
                break;
            }else{
                ad+=(s[j]-s[i])/2;
            }
        }
        if(n%2==1)
            if((ad+s[n/2])!=(s[n-1]+s[0])/2)
                flag=0;
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
