#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100005];
int unq[100005];
bool vis[100005];
set<int> ss;
int main()
{
    memset(vis,0,sizeof vis);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        ss.insert(s[i]);
        unq[i]=ss.size();
    }
    long long ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(vis[s[i]]==false){
            ans+=unq[i+1];
            vis[s[i]]=true;
        }else{
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}
