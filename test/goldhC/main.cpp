#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long s[50];
int n;
set<long long>st;

void dfs(int x,long long ans){
    if(x==n-1){
        st.insert(ans+s[x]);
        st.insert(ans-s[x]);
    }else{
        dfs(x+1,ans+s[x]);
        dfs(x+1,ans-s[x]);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        while(st.size())
        {
            st.erase(st.begin());
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&s[i]);
        }
        dfs(0,0);
        long long ans=st.size();
        printf("%lld\n",ans);
    }
    return 0;
}
