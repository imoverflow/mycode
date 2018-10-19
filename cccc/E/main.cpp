#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

int s[100005];
long long pre[100005];
int main()
{
    int n,m;
    pre[0]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+s[i];
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if((pre[r]-pre[l-1])%2==0)
        {
            printf("Sim\n");
        }else{
            printf("Nao\n");
        }
    }
    return 0;
}
