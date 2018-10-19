#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
typedef  long long LL;
const LL mod = 1e9+7;
int a[N], b[N], pos[N];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++)  scanf("%d", &a[i]);
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=a[i], cnt=0, j, sum=0;
            b[++cnt]=i;
            for(j=i+1;j<=n&&cnt<k;j++)
                if(a[j]>x)  b[++cnt]=j;

            if(cnt==k)
            {
                int num=1;
                for(;j<=n;j++)
                {
                    if(a[j]<x) num++;
                    else break;
                }
                sum+=num;
                for(j=i-1;j>=1&&cnt>=1;j--)
                {
                    if(a[j]<x) sum+=num;
                    else
                    {
                        if(cnt==1) break;
                        num=b[cnt]-b[cnt-1];
                        cnt--;
                        sum+=num;
                    }
                }
            }
            else
            {
                for(j=i-1;j>=1&&cnt<k;j--)if(a[j]>x) b[++cnt]=j;
                if(cnt==k)
                {
                    sort(b+1,b+cnt+1);
                    int num=n-b[cnt]+1;
                    sum+=num;
                    for(;j>=1&&b[cnt]>=i;j--)
                    {
                        if(a[j]<x) sum+=num;
                        else
                        {
                            if(b[cnt]==i) break;
                            num=abs(b[cnt]-b[cnt-1]);
                            cnt--;
                            sum+=num;
                        }
                    }
                }
            }
            //printf("%d %d\n",i, sum);
            ans+=(LL)x*sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
