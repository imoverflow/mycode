#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char ans[1000006];
int main()
{
    long long n;
    scanf("%I64d",&n);
    if((n*(n+1)/2)%2==0)
    {
        long long ans1=0; //+
        long long ans2=0; //-
        if(n%2!=0)
        {
            for(int i=1,j=n;i<j;i++,j--)
            {
                if(i%2==0)
                {
                    ans[i]='+';
                    ans[j]='-';
                    ans1+=i;
                    ans2+=j;
                }else{
                    ans[i]='-';
                    ans[j]='+';
                    ans1+=j;
                    ans2+=i;
                }
            }
            if(ans1<ans2)
                ans[(n+1)/2]='+';
            else if(ans1>ans2)
                ans[(n+1)/2]='-';
        }else{
            for(int i=1,j=n;i<j;i++,j--)
            {
                if(i%2==0)
                {
                    ans[i]=ans[j]='+';
                }else{
                    ans[i]=ans[j]='-';
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
    return 0;
}
