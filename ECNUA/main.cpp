#include <iostream>
#include <stdio.h>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//struct node{
//    int x,r,id;
//}s[100005];
//
//bool cmp(const struct node &a,const struct node &b)
//{
//    return
//}
//int main()
//{
//    int t;
//    cin>>t;
//    for(int i=1;i<=t;i++)
//    {
//        int a,b;
//        scanf("%d%d",&a,&b);
//        s[i].x=a;
//        s[i].r=b;
//        s[i],id=i;
//    }
//    sort(s+1,s+t+1,cmp);
//    return 0;
//}
//long long solve(long long x,long long n)
//{
//    return (x%n)*(n);
//}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
long long solve(long long x,long long i)
{
    return lcm(x,i)/x;
}
int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    for(int i=2;i<=n;i++)
    {
        printf("%lld\n",solve(x,i));
    }
    return 0;
}
