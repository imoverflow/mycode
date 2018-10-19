#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int s[100005]={0};
    int n,a;
    scanf("%d",&n);
    int p=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        s[a]=1;
        while(s[p]==1)
        {
            printf("%d ",p);
            p--;
        }
        printf("\n");
    }

    return 0;
}
