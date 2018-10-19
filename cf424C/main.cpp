#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ma[10000007]={0};
int vis[10000007]={0};
queue <int>g;
int main()
{
    int n,k;
    long long pre[20005];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(i!=0)
            pre[i]=a+pre[i-1];
        else
            pre[i]=a;
    }
    for(int i=0;i<k;i++)
    {
        int a;
        scanf("%d",&a);
        ma[a+4000000]++;
        g.push(a);
    }
    int ans=0;
    while(g.size()){
        int p=g.front();
        g.pop();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            long long ans1=p+pre[i];
            memset(vis,0,sizeof vis);
            int cnt=0;
            for(int j=0;j<i;i++)
            {
                cnt++;
                if(j>0)
                    vis[pre[j]-pre[j-1]+4000000]++;
                else
                    vis[pre[j]+4000000]++;
            }
            int flag=1;
            for(int j=i+1;j<n;j++)
            {
                if(ma[ans1+pre[j]+4000000]<vis[ans1+pre[j]+4000000])
                {
                    vis[ans+pre[j]+4000000]++;
                    cnt++;
                }else{
                    flag=0;
                }
                if(flag==0)
                    break;
            }
            if(flag&&cnt==k)
                ans++;
        }
    }
    return 0;
}
