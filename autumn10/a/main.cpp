#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int s[100005];
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        long long sum=0;
        scanf("%d%d",&n,&k);
        stack<long long>ss;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            sum+=s[i];
        }
        if(sum%k!=0)
        {
            printf("Case #%d: -1\n",cas++);
            continue;
        }
        long long avg=sum/k;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ss.push(s[i]);
        }
        while(!ss.empty())
        {
            long long p=ss.top();
            ss.pop();
            if(p<avg)
            {
                while(p<avg)
                {
                    ans++;
                    p+=ss.top();
                    ss.pop();
                }
                if(p>avg)
                {
                    ans++;
                    ss.push(p-avg);
                }
            }else if(p>avg){
                ans++;
                ss.push(p-avg);
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
