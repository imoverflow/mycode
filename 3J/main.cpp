#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
bool cmp(const int a,const int b)
{
    return a>b;
}
int main()
{
    int t,s[1000];
    scanf("%d",&t);
    while(t--)
    {
        int cou=0,ma=-100;
        do
        {
            scanf("%d",&s[cou++]);
        }while(getchar()!='\n');
        sort(s,s+cou,cmp);
        for(int i=0;i<cou-1;i++)
        {
            for(int j=i+1;j<cou;j++)
            {
                if(ma>=s[j]) goto label;
                ma=max(ma,gcd(s[i],s[j]));
            }
        }
        label:printf("%d\n",ma);
    }
    return 0;
}
