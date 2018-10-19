#include <iostream>
#include <stdio.h>
using namespace std;
long long sum(int k)
{
    long long su=1;
    for(int i=0;i<k;i++)
    {
        su*=10;
    }
    return su;
}
int main()
{

        long long n;
        int k,ans=0,j=10,num=0,cnt=0;
        cin>>n>>k;
        long long p=n;
        while(p!=0)
        {
            if(p%10==0)
                cnt++;
            num++;
            p/=10;
        }
        if(k>cnt)
            printf("%d\n",num-1);
        else if(n==0)
            printf("0\n");
        else
        {
            while(n!=0)
            {
                if(n%(sum(k))==0)
                {
                    break;
                }else
                {
                    if(n%j!=0)
                    {
                        n-=(j/10)*((n%j)/(j/10));
                        n/=10;
                        ans++;
                    }else
                        j*=10;
                }
            }
            printf("%d\n",ans);
        }
    return 0;
}
