#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[100000005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int len=strlen(s);
    vector <char> g1;
    vector <char> g2;
    for(int i=0;i<len;i++)
    {
        g2.push_back(s[i]);
    }
    for(int i=0;i<n;i++)
    {
        vector<char>::iterator it;
        vector<char>::iterator en;
        if(i%2==0)
        {
            g1.clear();
            it=g2.begin();
            en=g2.end();
        }
        else
        {
            g2.clear();
            it=g1.begin();
            en=g1.end();
        }
        for(;it-en<=0;it+=2)
        {
            for(int j=0;j<(*it)-'0';j++)
            {
                if(i%2==0)
                    g1.push_back(*(it+1));
                else
                    g2.push_back(*(it+1));
            }
        }
    }
    if(n%2==1)
    {
        vector<char>::iterator it=g1.begin();
        printf("%c",*(it+k));
    }else{
        vector<char>::iterator it=g2.begin();
        printf("%c",*(it+k));
    }
    printf("\n");
    return 0;
}
