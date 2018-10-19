#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[100000];
//bool cmp(int &a,int &b)
//{
//    return abs(a)>abs(b);
//}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<2*n;i++)
        {
            scanf("%lld",&s[i]);
        }
        sort(s,s+n*2);
        long long sum=0;
        for(int i=0;i<2*n;i+=2)
        {
            sum+=abs(s[i]-s[i+1]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
