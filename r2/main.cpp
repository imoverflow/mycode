#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int s[5005][5005];
int a,b,k,m,n,o,c[5005],l[5005],x[100005];
int main()
{
    pair<int ,int> p[100];
    scanf("%d%d%d",&a,&b,&k);
    x[0]=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&m,&n,&x[i]);

        if(m==1)
            l[--n]=i;
        else
            c[--n]=i;
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("%d ",x[max(l[i],c[j])]);
        }
        printf("\n");
    }
    return 0;
}
