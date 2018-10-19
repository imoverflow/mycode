#include <iostream>
#include <stdio.h>
using namespace std;

int s[10005];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int t,ans=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            for(int j=0;j<i;j++)
                if(gcd(s[i],s[j])==1)
                    ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
