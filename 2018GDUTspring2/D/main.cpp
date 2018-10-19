#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[1005];
char t[1005];
vector<pair<int,int> >v;
int main()
{
    v.clear();
    scanf("%s",s+1);
    strcpy(t+1,s+1);
    int len=strlen(s+1);
    sort(t+1,t+len+1);
    for(int i=1;i<=len;i++)
    {
        if(s[i]!=t[i])
        {
            for(int j=i;j<=len;j++)
            {
                if(s[j]==t[i])
                {
                    v.push_back(make_pair(j,i));
                    swap(s[i],s[j]);
                    break;
                }
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        printf("%d %d\n",v[i].first,v[i].second);
    }
    return 0;
}
