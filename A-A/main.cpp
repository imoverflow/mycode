#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int v[120];
    char t;
    char s[]={'p','q','r','u','v','w','x','y','z'};
    while(n--)
    {
        int m=0;
        do
        {
            scanf("%d",&v[m++]);
            t=getchar();
        }while(t!='\n');
        for(int i=0;i<m-1;i++)
        {
            if(v[i]<0)
                printf("%d%c",v[i],s[i]);
            else if(v[i]>0&&i!=0||)
                printf("+%d%c",v[i],s[i]);
            else if(v[i]>0&&i==0)
                printf("%d%c",v[i],s[i]);
        }
        if(v[m-1]<0)
                printf("%d",v[m-1]);
            else if(v[m-1]>0)
                printf("+%d",v[m-1]);
        printf("\n");
    }
    return 0;
}
