#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int equ(int a[3])
{
    if(a[0]==a[1]||a[0]==a[2]||a[1]==a[2])
        return 1;
    else
        return 0;
}
int main()
{
    int a,b,c,d;
    int s[3]={0};
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int n=0;
        scanf("%d %d %d",&s[0],&s[1],&s[2]);
        sort(s,s+3);
        do
        {
            if(equ(s)==1)
            {
                printf("YES\n");
                n=1;
                break;
            }else
            {
                s[0]+=2;
                s[2]-=1;
                s[1]-=1;
                sort(s,s+3);
            }
        }while(s[0]>0&&s[1]>0&&s[2]>0);
        if(n==0)
            printf("NO\n");
    }

    return 0;
}
