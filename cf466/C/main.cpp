#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[100005];
set<char>ss;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        ss.insert(s[i]);
    if(k>n)
    {
        printf("%s",s);
        for(int i=0;i<k-n;i++)
            printf("%c",*ss.begin());
    }else{
        for(int i=k-1;i>=0;i--)
        {
            set<char>::iterator it=ss.upper_bound(s[i]);
            if(it!=ss.end())
            {
                for(int j=0;j<i;j++)
                {
                    printf("%c",s[j]);
                }
                printf("%c",*it);
                for(int j=i+1;j<k;j++)
                {
                    printf("%c",*ss.begin());
                }
                break;
            }
        }
    }
    return 0;
}
