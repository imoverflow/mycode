#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,s[100005],find=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&s[i]);
    }
    sort(s,s+t);
    for(int i=0;i<=t-3;i++)
    {
        if(s[i]+s[i+1]>s[i+2])
        {
            find=1;
            break;
        }
    }
    if(find)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
