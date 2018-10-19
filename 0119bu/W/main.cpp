#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
bool vis[200005];
int main()
{
    int n,k;
    memset(vis,0,sizeof vis);
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    stack<int>s;
    int need=1;
    for(int i=0;i<k;i++)
    {
        vis[a[i]]=true;
        s.push(a[i]);
        while(!s.empty()&&need==s.top())
        {
            s.pop();
            need++;
        }
    }
    while(need<=n)
    {
        int t;
        if(!s.empty())
            t=s.top();
        else
            t=n+1;
        for(int i=t-1;i>=need;i--)
        {
            if(vis[i])
            {
                printf("-1\n");
                return 0;
            }else{
                s.push(i);
                a[k++]=i;
                vis[i]=true;
            }
            while(!s.empty()&&s.top()==need)
            {
                s.pop();
                need++;
            }
        }
    }
    if(!s.empty())
        printf("-1\n");
    else{
        for(int i=0;i<k;i++)
        {
            printf("%d%c",a[i],i!=k-1?' ':'\n');
        }
    }
    return 0;
}
