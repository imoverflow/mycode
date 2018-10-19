#include <iostream>
#include <stdio.h>
using namespace std;
struct{
    int zero,one;
}s[100005];
int main()
{
    s[1].one=1;
    s[1].zero=0;
    for(int i=2;i<=100000;i++)
    {
        s[i].zero=(s[i-1].one+s[i-1].zero)%10007;
        s[i].one=s[i-1].zero%10007;
    }
//    for(int i=0;i<6;i++)
//    {
//        printf("%d  %d\n",s[i].all,s[i].zero);
//    }
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("%d\n",(s[n].one+s[n].zero)%10007);
    }
    return 0;
}
