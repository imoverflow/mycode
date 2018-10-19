#include <iostream>
#include <bits/stdc++.h>
using namespace std;
deque<char>q;
char s[200005];
int t[200005];
int pre[200005];
stack<pair<int,char> >ss;
int main()
{
    int n,m;
    cin>>n>>m;
    scanf("%s",s+1);
    memset(t,-1,sizeof -1);
    for(int i=1;i<=n;i++)
    {
        if(ss.empty()||s[i]=='(')
        {
            ss.push(make_pair(i,s[i]));
        }else{
            if(ss.top().second=='(')
            t[i]=ss.pop().first;
        }
        pre[i]=pre[i-1]+t[i]==-1?0:i-t[i]+1;
    }
    for(int i=m-1;i<n;i++)
    {
        if(t[i]==-1) continue;
        if(pre[i]-pre[i-m-1])
    }
    return 0;
}
