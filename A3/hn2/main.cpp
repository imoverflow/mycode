#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int n,k,a,b;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    int p=k;
    if(a>b)
    {
        while(k)
        {
            int m=0;
            if(a/k+(a%k!=0)<b+2&&b>0||a/k+(a%k!=0)<b+2&&a<=k)
            {
                for(int i=0;i<a;i++)
                {
                    printf("G");
                    for(int j=0;j<k&&m<b;j++)
                    {
                        printf("B");
                        m++;
                    }
                }
                break;
            }
            k--;
        }
        if(k==0)
            printf("NO");
    }else
    {
        while(k)
        {
            int m=0,l=0;
            if(b/k+(b%k!=0)<a+2&&a>0||b/k+(b%k!=0)<a+2&&b<=k)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<k&&m<b;j++)
                    {
                        printf("B");
                        m++;
                    }
                    if(l<a)
                    {
                        printf("G");
                        l++;
                    }
                }
                break;
            }
            k--;
        }
        if(k==0)
            printf("NO");
    }

}

