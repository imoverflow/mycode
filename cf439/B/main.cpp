#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s1[2005];
int s2[2005];
int main()
{
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    if(b-a>=9) printf("0\n");
    else{
        long long res=1;
        for(int i=a%10+1;i<=b%10+(b%10<(a%10+1))*10;i++)
        {
            res*=i;
        }
        if(a==b)
            printf("1\n");
        else
        printf("%d\n",res%10);
    }
    return 0;
}
