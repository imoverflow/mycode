#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int s[1001]={0};
        int e[1001]={0};
        int flag=0,flag1=0,num=1,m=0;
        scanf("%d",&b);
        for(int j=0;j<b;j++)
        {
            scanf("%d",&c);
            s[c]++;
            if(s[c]>flag)
                flag++;
            else if(s[c]==flag)
                num++;
        }
        for(int j=0;j<1001;j++)
        {
            if(s[j]==flag)
                e[++flag1]=j;
        }
        sort(e,e+(flag1-1)*num+1);
        for(int j=1;j<flag1*num;j++)
        {
            if(e[j]==e[j+1])
                continue;
            if(m!=0)
            {
                printf(" %d",e[j]);
            }
            else
            {
                printf("%d",e[j]);
                m=1;
            }

        }
        printf("\n");

    }
    return 0;
}
