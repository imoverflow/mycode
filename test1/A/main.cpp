#include <bits/stdc++.h>

using namespace std;

long long s[1000006];
long long sum[1000006];
int main()
{
    int cnt=0;
    for(int i=2;i<10000;i++)
    {
        int flag=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            s[cnt++]=i;
        }
    }
    for(int i=0;i<100;i++)
    {
        printf("%d %d\n",i,s[i]);
    }
}
