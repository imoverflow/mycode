#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[1000006];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        int k=(n-1)/2;
        int maxp=0;
        int p;
        if(n%2)
        {
            for(int i=k;i>=0&&s[k]==s[i];i--)
                maxp++;
            for(int i=k+1;i<n&&s[k]==s[i];i++)
                maxp++;
            p=1;
        }else{
            for(int i=k;i>=0&&s[k]==s[i];i--)
                maxp++;
            for(int i=k+1;i<n&&s[k+1]==s[i];i++)
                maxp++;
            p=s[k+1]-s[k]+1;
        }
        printf("%d %d %d\n",s[k],maxp,p);
    }
    return 0;
}
