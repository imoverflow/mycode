#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];
map<int,int>ma1;
map<int,int>ma2;
set<int>used;
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    set<int>s1;
    set<int>s2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(s1.find(a[i])==s1.end())
            s1.insert(a[i]);
        else
            s1.erase(a[i]);
        ma1[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(s2.find(b[i])==s2.end())
            s2.insert(b[i]);
        else
            s2.erase(b[i]);
        ma2[b[i]]=i;
    }
    if(!s1.empty())
    {
        set<int>::iterator it=s1.begin();
        while(it!=s1.end())
        {
            ans=max(ans,*it);
            used.insert(*it);
            it++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(used.find(a[i])!=used.end())
            continue;
        int maxd=0;
        int flag=1;
        for(int j=i+1;j<ma1[a[i]];j++)
        {
            if(a[j]<a[i])
                maxd=max(maxd,a[j]);
            else
            {
                flag=0;
                ans=max(a[i],ans);
                break;
            }
        }
        if(flag)
        {
            ans=max(maxd,ans);
            i=ma1[a[i]];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(used.find(b[i])!=used.end())
            continue;
        int maxd=0;
        int flag=1;
        for(int j=i+1;j<ma2[b[i]];j++)
        {
            if(b[j]<b[i])
                maxd=max(maxd,b[j]);
            else
            {
                flag=0;
                ans=max(b[i],ans);
                break;
            }
        }
        if(flag)
        {
            ans=max(maxd,ans);
            i=ma2[b[i]];
        }
    }
    printf("%d\n",ans);
    return 0;
}
