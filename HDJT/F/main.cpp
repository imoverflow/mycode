#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[1005][1005];
int ans[1005];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
vector<int>v;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
//        priority_queue<vector<int>,vector<int>,greater<int> >q;
        queue<int>q1;
        queue<int>q2;
        memset(ans,0,sizeof ans);
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&s[i][j]);
                ans[j]+=s[i][j];
            }
        }
        int p=pow(k,1.0/m)+1;
        for(int i=0;i<n;i++)
        {
            sort(s[i],s[i]+m,cmp);
            if(i==0)
            {
                for(int j=0;j<p;j++)
                {
                    q1.push(s[i][j]);
                }
            }else{
                if(i%2==1)
                {
                    while(!q1.empty())
                    {
                        int z=q1.front();
                        q1.pop();
                        for(int j=0;j<p;j++)
                        {
                            q2.push(s[i][j]+z);
                        }
                    }
                }else{
                    while(!q2.empty())
                    {
                        int z=q2.front();
                        q2.pop();
                        for(int j=0;j<p;j++)
                        {
                            q1.push(s[i][j]+z);
                        }
                    }
                }
            }
        }
//        printf("%d\n",q1.size());
//        printf("%d\n",q2.size());
        if(q1.empty())
        {
            while(!q2.empty())
            {
                int z=q2.front();
                v.push_back(z);
                q2.pop();
            }
            sort(v.begin(),v.end(),cmp);
            long long ans=0;
            for(int i=0;i<k;i++)
            {
                ans+=v[i];
            }
            printf("%lld\n",ans);
        }else{
            while(!q1.empty())
            {
                int z=q1.front();
                v.push_back(z);
                q1.pop();
            }
            sort(v.begin(),v.end(),cmp);
//            for(int i=0;i<v.size();i++)
//                printf("%d  ",v[i]);
            long long ans=0;
            for(int i=0;i<k;i++)
            {
                ans+=v[i];
            }
            printf("%lld\n",ans);
        }
        v.clear();
    }
    return 0;
}
