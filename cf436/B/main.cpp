#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[500];
int main()
{
    int n;
    cin>>n;
    scanf("%s",s);
    set<char>ss;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            ss.insert(s[i]);
        }else{
            ans=max(ans,(int)ss.size());
            ss.clear();
        }
    }
    ans=max(ans,(int)ss.size());
    printf("%d\n",ans);
    return 0;
}
