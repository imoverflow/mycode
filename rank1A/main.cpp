#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int s[100005];
int n,k;
int dfs(int x)
{
    if(x==k) return 1;
    else
}
int main()
{
    s[0]=0;
    s[1]=1;
    scanf("%d%d",&n,&k);

    if(n<=k)
        printf("%d\n",s[k]);
    else
        printf("%d\n",n-k);
    return 0;
}
