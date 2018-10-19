#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long x=1ll*n*(a-1)+b;
        long long x1=a+b;
        if(n%2==0)
        {
            if(x1%2==0)
            {
                if(a%2==1)
                    printf("%I64d\n",(a-1)*(n/2)+(b+1)/2);
                else
                    printf("%I64d\n",(a-1)*(n/2)+(b+1)/2);
            }else{
                if(a%2==1)
                    printf("%I64d\n",(a-1)*(n/2)+(b+1)/2+n*n/2);
                else
                    printf("%I64d\n",(a-1)*(n/2)+(b+1)/2+n*n/2);
            }
        }else{
            if(x1%2==0)
            {
                if(a%2==1)
                    printf("%I64d\n",(a-1)/2*n+(b/2)+1);
                else
                    printf("%I64d\n",(a-1)/2*n+(n/2)+1+b/2);
            }else{
                if(a%2==1)
                    printf("%I64d\n",(a-1)/2*n+(b/2)+n*n/2+1);
                else
                    printf("%I64d\n",(a-1)/2*n+(n/2)+1+b/2+n*n/2+1);
            }
        }
    }
    return 0;
}
