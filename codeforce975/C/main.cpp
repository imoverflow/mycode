#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[200005];
int t[200005];
long long pre[200005];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        t[i]=s[i];
        if(i==0)
        {
            pre[i]=s[i];
        }else{
            pre[i]=pre[i-1]+s[i];
        }
    }
    int die=0;
    int now=0;
    long long m=0;
    for(int i=0;i<q;i++)
    {
        long long x;
        scanf("%I64d",&x);
        m+=x;
        int p=upper_bound(pre,pre+n,m)-pre;
        if(p==n)
        {
            printf("%d\n",n);
            m=0;
        }else{
            if(pre[p]>m)
                printf("%d\n",n-p);
            else
                printf("%d\n",n-p-1);
        }
    }
    return 0;
}
