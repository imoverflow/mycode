#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long a[200];
long long b[200];
int main()
{
    int n,m;
    cin>>n>>m;
    long long max1=((long long)1<<62);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int k=0;k<n;k++)
    {
        long long max2=-((long long)1<<62);
        for(int i=0;i<n;i++)
        {
            if(i==k) continue;
            for(int j=0;j<m;j++)
            {
                if(a[i]*b[j]>max2)
                {
                    max2=a[i]*b[j];
                }
            }
        }
        max1=min(max1,max2);
    }
    printf("%I64d\n",max1);
    return 0;
}
