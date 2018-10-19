#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int s[1000000];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    sort(s,s+n);
    int ans=n,cou=0;
    int p=0;
    for(int i=n/2;i<n;i++)
    {
        if(s[i]*2<=s[p]&&p<n/2)
        {
            p++;
            ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
