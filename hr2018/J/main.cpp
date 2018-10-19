#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int s[100005];
int a[100005];
int b[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[n-i-1]=a[i];
        }
        bool flag1=true,flag2=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]<s[i])
            {
                flag1=false;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]<s[i])
            {
                flag2=false;
                break;
            }
        }
        if(flag1&&flag2)
        {
            printf("both\n");
        }else if(flag1)
        {
            printf("front\n");
        }else if(flag2)
        {
            printf("back\n");
        }else{
            printf("none\n");
        }
    }
    return 0;
}
