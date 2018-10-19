#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>v[505];
void kmp_pre(char x[],int p)        //两种处理方法
{
    int i,j;
    int m=strlen(x);
    v[p].resize(m+2);
    v[p][0]=-1;
    j=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j]) j=v[p][j];
        v[p][++i]=++j;
    }
}
int kmp_count(int r,char x[],int m,char y[],int n)
{
    int i,j;
    int ans=0;
//    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j&&y[i]!=x[j])
            j=v[r][j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j=v[r][j];
        }
    }
    return ans;
}

char s[505][2005];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int ans=-1;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            kmp_pre(s[i],i);
        }
        v[n].resize(10);
        stack<int>ss;
        ss.push(0);
        for(int i=1;i<n;i++)
        {
            int x=ss.top();
            int flag=0;
            while(kmp_count(x,s[x],strlen(s[x]),s[i],strlen(s[i])))
            {
                ss.pop();
                flag=1;
                if(!ss.empty())
                    x=ss.top();
                else
                    break;
            }
            if(!ss.empty())
                ans=i+1;
//            cout<<"ok"<<endl;
            ss.push(i);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
