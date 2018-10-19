#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void strcpy1(char *s1,string s2)
{
    for(int i=0;i<s2.length();i++)
    {
        *(s1+i)=s2[i];
    }
}
char s[10000005]={0};
char s1[10000005]={0};
pair<int ,string> pii;
vector <pair<int ,string> > g;
bool cmp(pair<int ,string> &a,pair<int ,string> &b)
{
    if(a.first==b.first)
        return a.second.length()>b.second.length();
    else
        return a.first<b.first;
}
int main()
{
    int n;
    scanf("%d",&n);
    int len=1;
    for(int i=0;i<n;i++)
    {
        getchar();
        char t;
        int cnt=0;
        while(scanf("%c",&t))
        {
            if(t>='a'&&t<='z')
            {
                s1[cnt++]=t;
            }else{
                s1[cnt]=0;
                break;
            }
        }
        string s11=s1;
        int p;
        scanf("%d",&p);
        for(int j=0;j<p;j++)
        {
            int a;
            scanf("%d",&a);
            pair<int ,string> z;
            z.first=a;
            z.second=s11;
            g.push_back(z);
        }
    }
    sort(g.begin(),g.end(),cmp);
    pair<int ,string> y;
    vector<pair <int ,string> >::iterator it=g.begin();
    int len1=len;
    for(;it!=g.end();)
    {
        y.first=len;
        it=lower_bound(it,g.end(),y);
        if(it-g.end()>=0) break;
        strcpy1(s+(*it).first-1,(*it).second);
//        if((*it).second.length()!=1)
//            len=(*it).first+(*it).second.length()-1;
//        else
//            len=(*it).first+(*it).second.length();
        len=(*it).first+1;
        len1=(*it).first+(*it).second.length()-1;
    }
    for(int i=0;i<len1;i++)
    {
        if(s[i]==0)
            printf("a");
        else
            printf("%c",s[i]);
    }
    return 0;
}
