#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,h,a,b,k;
    cin>>n>>h>>a>>b>>k;
    for(int i=0;i<k;i++)
    {
        long long x1,f1,x2,f2;
        scanf("%I64d%I64d%I64d%I64d",&x1,&f1,&x2,&f2);
        if(x1==x2)
        {
            printf("%d\n",abs(f1-f2));
            continue;
        }else{
            long long ans=0;
            ans+=abs(x1-x2);
            if(f1>=a&&f1<=b)
            {
                ans+=abs(f2-f1);
                printf("%d\n",ans);
                continue;
            }
            if(abs(f1-a)<abs(f1-b))
            {
                ans+=abs(f1-a);
                ans+=abs(f2-a);
            }else{
                ans+=abs(f1-b);
                ans+=abs(f2-b);
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
