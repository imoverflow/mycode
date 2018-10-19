#include <iostream>
#include <stdio.h>
using namespace std;
int pow(int a,int b)
{
    int res=1;
    for(int i=0;i<b;i++)
    {
        res*=a;
    }
    return res;
}
int main()
{
    int t,n,s[40];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cou=0;
        while(n>0)
        {
            s[cou++]=n%2;
            n/=2;
        }
        int sum=0;
        for(int i=0;i<cou;i++)
        {
            sum+=s[i]*pow(2,cou-1-i);
        }
        printf("%d\n",sum);
    }
    return 0;
}
